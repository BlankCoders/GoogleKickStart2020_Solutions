import java.io.*;
import java.util.*;
public class Solution
{
    private static BufferedReader br;
    private static StringBuilder sb;
    private static Pair[] points;
    static class Pair implements Comparable<Pair>
    {
        long f, s;
        Pair(long f, long s){this.f = f;this.s = s;}
        public int compareTo(Pair b){return Long.compare(this.f,b.f);}
    }
    private static void shuffleArray(long[] arr)
    {
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i)
        {
            long tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
    }
    private static long abs(long N){return N>=0?N:-N;}
    private static long calc(int N, long start)
    {
        long count=0;
        for(int i=0;i<N;i++) count+=abs(points[i].f-start++);
        return count;
    }
    private static void solve(int T) throws Exception
    {
        int i,N;
        N=Integer.parseInt(br.readLine().trim());
        points=new Pair[N];
        long[] X=new long[N];
        long[] Y=new long[N];
        long ans=0,tmp2=Long.MAX_VALUE/10;
        for(i=0;i<N;i++)
        {
            String[] s=br.readLine().trim().split(" ");
            int XX=Integer.parseInt(s[0]);
            int YY=Integer.parseInt(s[1]);
            X[i]=XX; Y[i]=YY;
            points[i]=new Pair(XX,YY);
        }
        shuffleArray(X); shuffleArray(Y);
        Arrays.sort(X); Arrays.sort(Y);
        Arrays.sort(points);
        for(i=0;i<N;i++) ans+=Math.abs(Y[N/2]-points[i].s);
        long l=-(long)2e9,r=(long)2e9;
        while (r-l>4)
        {
            long m1=l+(r-l)/3;
            long m2=r-(r-l)/3;
            long f1=calc(N,m1);
            long f2=calc(N,m2);
            if(f1>=f2) l=m1;
            else r=m2;
        }
        for(long x=l;x<=r;x++) tmp2=Math.min(tmp2,calc(N,x));
        sb.append("Case #").append(T).append(": ");
        sb.append(ans+tmp2).append("\n");
    }
    public static void main(String[] args) throws Exception
    {
        br=new BufferedReader(new InputStreamReader(System.in));
        sb=new StringBuilder();
        int T=Integer.parseInt(br.readLine().trim());
        for(int i=1;i<=T;i++) solve(i);
        System.out.println(sb);
    }
}
