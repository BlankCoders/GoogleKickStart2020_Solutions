import java.util.*;
import java.io.*;
import java.lang.*;
class Solution
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t,n,i,max,curr,prev,count,j;
        t=sc.nextInt();
        j=t;
        while(t>0)
        {
            n=sc.nextInt();
            max=-1;
            count=0;
            prev=sc.nextInt();
            for(i=0;i<n-1;i++)
            {
                curr=sc.nextInt();
                if(prev>max)
                {
                    max=prev;
                    if(curr<prev)
                     count++;
                }
                prev=curr;
            }
            if(prev>max)
             count++;
        System.out.println(String.format("Case #%d: %d", (j-t+1), count));
            t--;
        }
    }
}