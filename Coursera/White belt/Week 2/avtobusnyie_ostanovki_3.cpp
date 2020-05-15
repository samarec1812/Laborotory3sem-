//container set avtobusnyie_ostanovki-3
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;
int main() {
    int Q;
    cin >> Q;
    int k = 0;
    bool f1 = true;
    map<set<string>, int>s;
    string h;
    set<string>a;
    for (int i = 0; i < Q; ++i) {

        int n; cin >> n;
        for(int i =0; i < n; i++){
        cin>>h;
        a.insert(h);
    }
        if(!s.count(a)){
        s[a] =k++;
        cout<< "New bus "<<k << endl;
        }
else {
    cout << "Already exists for "<< s[a]+1 << endl;
}
a.clear();
    }

    return 0;
}