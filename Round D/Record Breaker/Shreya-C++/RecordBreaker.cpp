#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=0;i<t;i++){
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        int ans=0;
        int max=-1;
        if(n==1){
            ans=1;
        }
        else{
            for(int j=0;j<n-1;j++){
                if(a[j]>max){
                    max=a[j];
                    if(a[j]>a[j+1]){
                        ans++;
                    }
                }
            }
            if(a[n-1]>max){
                ans++;
            }
        }
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
    }
    return 0;
}
