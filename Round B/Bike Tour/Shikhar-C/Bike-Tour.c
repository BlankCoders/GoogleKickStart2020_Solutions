#include<stdio.h>
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
void solve()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int cnt=0;
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<n-1;i++)
    if(a[i]>max(a[i-1],a[i+1]))
    cnt++;
    printf("%d\n",cnt);
}
int main() {
    int t;
scanf("%d",&t);
for(int i=1;i<=t;i++)
{
    
    printf("Case #%d: ",i);
    solve();
}
}
