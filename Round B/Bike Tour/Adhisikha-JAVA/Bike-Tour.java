import java.util.*;
import java.io.*;
public class  Solution {
  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt();
    int k=1; // Scanner has functions to read ints, longs, strings, chars, etc.
    for (k = 1; k <= t; ++k) 
    {
      int n=in.nextInt();
      int arr[]=new int[n];
      for(int i=0;i<n;i++)
      arr[i]=in.nextInt();
      int peak=0;
      for(int i=1;i<n-1;i++)
      {
      if((arr[i]>arr[i-1]) && (arr[i+1]<arr[i]))
      peak++;
      }
      System.out.println("Case #" +k+ ": " + peak);
      
    }
  }
}
  
