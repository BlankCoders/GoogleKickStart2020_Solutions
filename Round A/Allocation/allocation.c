#include<stdio.h>
void makeheap(int[],int);
void heapsort(int[],int);

void heapsort(int x[],int n)
{
    int i,s,f,ivalue;
    for(i=n-1;i>0;i--)
    {
        ivalue=x[i];
        x[i]=x[0];
        f=0;
        if(i==1)
        s=-1;
        else
        s=1;
        if(i>2&&x[2]>x[1])
        s=2;
        while(s>=0&&ivalue<x[s])
        {
            x[f]=x[s];
            f=s;
            s=2*f+1;
            if(s+1<=i-1&&x[s]<x[s+1])
            s++;
            if(s>i-1)
            s=-1;
        }
        x[f]=ivalue;
    }
}

void makeheap(int x[],int n)
{
    int i,value,s,f;
    for(i=1;i<n;i++)
    {
        value=x[i];
        s=i;f=(s-1)/2;
        while(s>0&&x[f]<value)
        {
            x[s]=x[f];
            s=f;
            f=(s-1)/2;
        }
        x[s]=value;
    }
}


int main()
{
    int n,t,k,b;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d",&n,&b);
        int a[n],i,sum=0;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        makeheap(a,n);
        heapsort(a,n);   
        int ans=0;
        for(int i=0;i<n;i++)
		{
			if(a[i]<=b)
			{
				ans++;
				b-=a[i];
			}
		}
        printf("Case #%d: %d\n",k,ans);
        
    }
}
