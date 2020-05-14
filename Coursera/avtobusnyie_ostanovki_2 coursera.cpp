//container map avtobusnyie_ostanovki_2
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(){
map<vector<string>, int >a;
int Q;
cin >> Q;
    int k =1;
    bool f1 = true;
for(int i = 0; i < Q; ++i){
    vector<string>ss;

   int n; cin >> n;
f1= true;
     for(int j = 0; j < n; j++){
         string s;
         cin >> s;
        ss.push_back(s);
     }
    if(!a.empty()){
        for(auto &w: a){
            if(w.first == ss) {cout << "Already exists for" <<" "<<w.second<<endl;  f1 =false; break; }
        }
    }
    if(f1 == true){
     a[ss] = k;
     cout <<"New bus "<< k << endl;
    k++;}
}





return 0;
}