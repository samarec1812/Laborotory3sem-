#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using ll = long long; 
using namespace std; 

int maxim = INT_MIN; 
int main(){

    int n; cin >> n; 
  vector<int> a(n); 
    for(int i = 0; i < n; i++){
    cin >> a[i]; 
    }
   
    int index = 0; 
    for(int i = 0; i < n; i++){
        if(maxim < a[i]){
         maxim = a[i]; 
         index = i;   
        }
    }
    cout << index+1 ;
}
