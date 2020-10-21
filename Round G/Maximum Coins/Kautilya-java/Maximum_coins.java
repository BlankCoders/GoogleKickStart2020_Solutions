import java.util.Scanner;
import java.util.Arrays;
/* Name of the class has to be "Main" only if the class is public. */
class Solution
{
	public static void main (String[] args) throws java.lang.Exception
	{
		try {
		    Scanner sc = new Scanner(System.in);
		    int t,n,i,j,z,k;
		    long c,max;
		    t=sc.nextInt();
		    z=t;
		    while(t>0)
		    {
		        t--;
		        n=sc.nextInt();
		        int a [][] = new int[n][n];
		        c=max=0;
		        for(i=0;i<n;i++)
		        {
		            for(j=0;j<n;j++)
		             a[i][j]=sc.nextInt();
		        }
		        for(i=0;i<n;i++)
		        {
		            k=i;
		            for(j=0;j<n-i;j++)
		             {
		                 c=c+a[k][j];
		                 k++;
		                
		             }
		            
		             if(c>max)
		              max=c;
		              c=0;
		        }
		        for(i=0;i<n;i++)
		        {
		            k=i;
		            for(j=0;j<n-i;j++)
		             {
		                 c=c+a[j][k];
		                 k++;
		             }
		            
		             if(c>max)
		              max=c;
		              c=0;
		        }
		        System.out.println("Case #"+(z-t)+": "+max);
		    }
		} catch(Exception e) {
		}
	}
}
