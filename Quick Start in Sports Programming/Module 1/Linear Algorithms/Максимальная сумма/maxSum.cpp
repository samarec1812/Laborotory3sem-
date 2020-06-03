#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
using namespace std;



int main() {

    int n;
    cin >> n;
    vector<ll>a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = a[0];
    ll min_sum = 0, sum = 0;
  for(int i = 0; i < n; i++){
      sum += a[i];
      ans = max(ans, sum- min_sum);
      min_sum = min(min_sum, sum);
  }
    cout << ans;
    return 0;
}
