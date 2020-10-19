import java.util.Scanner;
import java.util.Arrays;
/* Name of the class has to be "Main" only if the class is public. */
class Solution
{
	public static void main (String[] args) throws java.lang.Exception
	{
		try {
		    Scanner sc = new Scanner(System.in);
		    int t,n,k,c,i,count,q,z;
		    t=sc.nextInt();
		    z=t;
		    while(t>0)
		    {
		        t--;
		        n=sc.nextInt();
		        k=sc.nextInt();
		        q=k;
		        int a [] =new int[n];
		        count=0;
		        for(i=n-1;i>=0;i--)
		        a[i]=sc.nextInt();
		        for(i=0;i<n;i++)
		        {
		            if(a[i]==1)
		             {
		                 while(i<n-1 && a[i]==(a[i+1]-1))
		                 i++;
		                  if(a[i]>=q)
		                   count++;
		             }
		        }
		          
		        System.out.println("Case #"+(z-t)+": "+count );
		    }
		} catch(Exception e) {
		}
	}
}
