#pragma once

#include <map>
#include <vector>
#include <mutex>
#include <future>

using namespace std;


template <typename K, typename V>
class ConcurrentMap {
public:
	static_assert(is_integral_v<K>, "ConcurrentMap supports only integer keys");

	struct Access {
		lock_guard<mutex> guard;
		V& ref_to_value;
	};

	explicit ConcurrentMap(size_t bucket_count) :segments(bucket_count) {}

	Access operator[](const K& key) {
		auto &Sub = segments[location(key)];
		return { lock_guard<mutex>(segments[location(key)].m),Sub.vault[key] };
	}

	map<K, V> BuildOrdinaryMap() {
		map<K, V> result;
		for (size_t i = 0; i < segments.size(); i++) {
			auto temp=lock_guard<mutex>(segments[i].m);
			for (const auto& item : segments[i].vault) {
				result[item.first] = item.second;
			}
		}
		return result;
	}
private:
	size_t location(const K& key) {
		int l = key % segments.size();
		if (l >= 0) return l;
		else return -l;
	}

	struct Submap {
		map<K, V> vault;
		mutex m;
	};

	vector<Submap> segments;
};
