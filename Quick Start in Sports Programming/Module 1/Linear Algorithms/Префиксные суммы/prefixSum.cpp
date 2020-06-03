#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
using namespace std;


int main() {

    int n, q;
    cin >> n >> q;
   vector<ll>a(n);
   vector<ll>sum(n);
for (int i = 0; i < n; i++) {
        cin >> a[i];
}
   sum[0] = a[0];
for(int i = 1; i < n; i++){
    sum[i] = sum[i-1] + a[i];
}
int left, right;
for(int i = 0; i < q; i++) {
         cin >> left >> right;
         cout << sum[right-1]-sum[left-1]+a[left-1] << "\n";
}
return 0;
}
