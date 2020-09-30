#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    int i = 1;
    
    cin >> t;
    
    while(t--) {
        
        int n,k,p;
        
        cin >> n >> k >> p;
        
        int a[n][k];
        int dp[n + 1][(n*k) + 1];
        
        memset(dp , 0xc0, sizeof(dp));
        dp[0][0] = 0;
    
        for(int i = 0; i < n; ++i) {
            
            memcpy(dp[i + 1] , dp[i], sizeof(dp[0]));
            
            for(int j = 0, s = 0; j < k; ++j) {
                
                cin >> a[i][j];
                s = s + a[i][j];
                
                for(int l = 0; (l + j + 1) <= p; ++l) {
                    
                    dp[i + 1][l + j + 1] = max( dp[i][l] + s, dp[i + 1][l + j + 1]);
                
                }
            }
        }
        
        cout << "Case #" << i << ": " << dp[n][p] << endl; 
        
        i++;
    }
     
}
