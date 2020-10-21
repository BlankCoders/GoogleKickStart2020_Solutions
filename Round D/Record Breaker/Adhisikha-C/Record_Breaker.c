#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int k=1;
    for(k=1;k<=t;k++)
    {
    int n;
    scanf("%d",&n);
    int arr[n];
    int c=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(i>0 && (arr[i]==arr[0]))//count of equal elements
            c++;
    }
    int max_ele=arr[0];
    int ans=0;
    for(int i=1;i<n-1;i++)
    {
     if(arr[i]>max_ele)
     {
     max_ele=arr[i];
     if(arr[i]>arr[i+1])
     ans++;
     }
    }

    if(arr[n-1]>max_ele)
        ans++;

    if(n==1)
    ans=1;

    if(n!=1 && arr[0]>arr[1])
    ans++;

    printf("Case #%d: %d",k,ans);
    printf("\n");
    }
return 0;

}
