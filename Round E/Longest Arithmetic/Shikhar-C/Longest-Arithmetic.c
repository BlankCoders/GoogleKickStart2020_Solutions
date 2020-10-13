#include<stdio.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
//Solution with O(n) time complexity with O(1) extra space
void solve()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    int ans=2;
    int len=2;
    for(int i=0;i<n-1;i++)
    {
        
        int diff=a[i+1]-a[i];
        for(int j=i+2;j<n;j++)
        {
            if(a[j]!=(a[i]+(j-i)*diff))
            {
                i=j-2;
                len=2;
                break;
            }
            else
            {
                len++;
                i=j-2;
                ans=max(ans,len);
            }
        }
    }
    printf("%d\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
}
