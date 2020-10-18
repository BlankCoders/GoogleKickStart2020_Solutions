import java.util.Scanner;
class Solution
{
    public static void main(String args[])
    {
        int t,n,i,k,d,w;
        Scanner sc= new Scanner (System.in);
        t=sc.nextInt();
        w=t;
        while(t>0)
       {
           t--;
           n=sc.nextInt();
           long a[] =new long[n];
           for(i=0;i<n;i++)
            a[i]=sc.nextLong();
            d=2;
            for(i=1;i<n-1;i++)
            {
                k=2;
                while(i<(n-1) && (a[i+1]-a[i])==(a[i]-a[i-1]))
                {
                    k++;
                    i++;
                }
                
                if(d<k)
                 d=k;
            }
            System.out.println("Case #"+(w-t)+": "+d);
       }
    }
}