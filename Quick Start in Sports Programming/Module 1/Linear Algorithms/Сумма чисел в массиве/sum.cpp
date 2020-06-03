#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long; 
using namespace std; 

int main(){

    int n; cin >> n; 
  vector<ll> a(n); 
    for(int i = 0; i < n; i++){
    cin >> a[i]; 
    }
    ll sum = 0; 
    for(const auto w: a){
    sum += w; 
    }
    cout << sum; 
}
