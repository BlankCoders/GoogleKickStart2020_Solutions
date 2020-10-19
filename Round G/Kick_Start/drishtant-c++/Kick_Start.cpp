/* Kickstart Round G Q1 solution in c++14(g++) by drishtantR1508 */
#include<bits/stdc++.h>
using namespace std ;
long long  solve (){
    string s ; cin >> s ;
    vector<int> v ;
    //cout << s.size() << endl;
    for(int j =0 ; j+3 < s.size() ; j++){
          string t = s.substr(j,4);
         if(t == "KICK")
               v.push_back(j);
           }
         long long  ans = 0 ;
     for(int j =0 ; j+4 < s.size() ; j++){
           string t = s.substr(j,5);
           if(t== "START"){
               int idx = j ;
               auto idx2 = upper_bound(v.begin() , v.end() ,idx) - v.begin();
               ans += idx2 ;
           }
     }
    return ans ;
}
int main(){
    int t ; cin >> t ;
    for(int i = 1 ; i <= t ; i++){
          long long  x = solve();
          cout << "Case #"<< i <<":" << " " << x ;
          cout << endl;
    }
}
