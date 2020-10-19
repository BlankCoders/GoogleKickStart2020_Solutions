import java.util.*;
import java.io.*;
public class  Solution {
  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt();
    int k=1; // Scanner has functions to read ints, longs, strings, chars, etc.
    for (k = 1; k <= t; ++k) 
    {
     String s=in.next();
     int len=s.length();
     long start=0,e=0,ans=0;
    for(int i=0;i<len-4;i++)
    {
        if(s.substring(i,i+4).equals("KICK"))
        {
            start++;
        }

        else if(s.substring(i,i+5).equals("START"))
        {
            ans+=start;
        }
    }
      System.out.println("Case #" +k+ ": " + ans);
      
    }
  }
}
  
