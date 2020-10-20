#include<bits/stdc++.h>
using namespace std;

double dp[5000][5000];
double sum[5000];
double s[5000];
double e[5000];
int main() 
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cout.precision(30);
	int t;
    cin >> t;
    for(int cases=1;cases<=t;cases++){
        cout << "Case #" << cases << ": ";
		int n;
        cin >> n;
        double a[n];
        
        for(int i=0;i<n;i++){
            cin >> a[i];
            s[i]=e[i]=0;
        }
        sum[0]=a[0];
        for(int i=1;i<n;i++)
            sum[i]=sum[i-1]+a[i];
        
        for(int i=0;i<n;i++)
            dp[0][i]=0;
        
        for(int i=1;i<n;i++){
            for(int j=0;i+j<n;j++){
                dp[i][j]=i*sum[i+j];
                if(j>0)
                    dp[i][j]-=i*sum[j-1];
                dp[i][j]+=s[j];
                dp[i][j]+=e[i+j];
                dp[i][j]/=i;
            }
            for(int j=0;i+j<n;j++){
                s[j]+=dp[i][j];
                e[i+j]+=dp[i][j];
            }
        }    
        
        cout << dp[n-1][0] << endl;
    }
	return 0;
}
