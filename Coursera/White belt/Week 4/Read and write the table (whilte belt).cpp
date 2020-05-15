#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
  ifstream input("input.txt");

input>>n >> m;
string a;

input.ignore(1);
     for(int i =0; i < n; i++){
         for(int j = 1; j <m; j++){
                 getline(input, a,',');
                 cout << setw(10)<<a<<" ";
  }
         getline(input, a);
         cout << setw(10)<<a<<endl;
     }
    return 0;
}