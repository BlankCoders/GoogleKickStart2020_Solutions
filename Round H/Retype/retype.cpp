#include<iostream>
using namespace std;
int main()
{
    long long int t,n,k,s,a,a1;
    cin>>t;
    for(long long int i=1;i<=t;i++)
    {
        cin>>n>>k>>s;
        a=n+k;
        a1=(k-1)+(k-s)+(n-s)+1;
        cout<<"Case #"<<i<<":"<<" "<<min(a,a1)<<"\n";
    }
    return 0;
}
