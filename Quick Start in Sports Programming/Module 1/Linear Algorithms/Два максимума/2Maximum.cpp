#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using ll = long long; 
using namespace std; 

ll mod = 1791791791; 

ll NextRand(ll &cur, ll a, ll b) {
    cur = (cur * a + b) % mod; 
    return cur; 
}

ll maxim = LLONG_MIN; 

void Print(vector<ll>a){
  for(const auto w : a) cout << w <<" "; 
}

int main(){

    
   ll n,cur, a, b; 
    cin >> n >> cur >> a >> b; 
  vector<ll> a1(n,0); 
    for(int i = 0; i < n; i++){
      a1[i] = NextRand(cur, a,b);
    }
   // Print(a1); 
int index = 0; 
    for(int i = 0; i < n; i++){
        if(maxim < a1[i]){
         maxim = a1[i]; 
         index = i;   
        }
    }
    
 ll maxim2 = LLONG_MIN; 
 ll index2 = 0; 
    for(int i = 0; i < n; i++){
           if(i != index){
               if(maxim2 < a1[i]){
           maxim2 = a1[i];
           index2 = i; 
           }
           }
    }
    cout << index+1 << " " << index2+1; 
 return 0;    
}
