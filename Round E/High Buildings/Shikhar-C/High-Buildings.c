#include<stdio.h>
void solve()
{
    int n,a,b,c;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    int tot=a+b-c;
    //tot distinct buildings visible in union
    if(tot>n)
    {
        printf("IMPOSSIBLE");
        return ;
    }
    
    //a-c disjoint building are visible from left for A
    //b-c disjoint buildings are visible from right for S
    //c common to both
    //1 1 1 ...(a-c) 3 3 3 3... (c) 1 1 1 .. 2 2 2 2 2...(b-c)
    if(n>=3||n==1)
    {
    int ans[n];
    for(int i=0;i<n;i++)
    ans[i]=-1;
    if(((a!=c)&&(b!=c))||((a==c)&&(b!=c)))
    {
    for(int i=0;i<a-c;i++)
    ans[i]=1;
    int cnt=b-c;
    for(int i=n-1;(i>=0)&&cnt;i--,cnt--)
    ans[i]=2;
    for(int i=a-c;i<a;i++)
    ans[i]=3;
    for(int i=0;i<n;i++)
    {
        if(ans[i]<0)
        printf("1 " );
        else
        printf("%d ",ans[i]);
    }
    }
    else
    {
      if(a==c)
      {
          if(b==c)
          {
              //It means same buildings are seen by both of them 
             if(a!=1)
             {
                for(int i=0;i<a-1;i++)
                ans[i]=3;
                for(int i=a-1;i<n-1;i++)
                ans[i]=1;
                ans[n-1]=3;
                for(int i=0;i<n;i++)
                printf("%d ",ans[i]);
             }
             else
             {
                 if(n==1)
                 printf("%d",1);
                 else
              printf("IMPOSSIBLE");  
             }
          }
      }
      else
      {
          if(b==c)
          {
              int last=b;
              for(int i=n-1;(i>=0)&&last;i--,last--)
              ans[i]=3;
              for(int i=0;i<a-b;i++)
              ans[i]=2;
              for(int i=0;i<n;i++)
              if(ans[i]<0)
              printf("1 ");
              else
              printf("%d ",ans[i]);
          }
      }
    }
    return ;
    }
    if(n==2)
    {
        if(c==2)
        printf("1 1");
        else
        {
        if(a==1)
        {
            if(b==2)
            printf("2 1");
            else
            printf("IMPOSSIBLE");
        }
        else
        {
            if(b==1)
            printf("1 2" );
            else
            printf("IMPOSSIBLE");
        }
        }
        return ;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        solve();
        printf("\n");
    }
}
