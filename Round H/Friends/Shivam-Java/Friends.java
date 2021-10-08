import java.io.*;
import java.util.*;
public class Solution
{
    private static BufferedReader br;
    private static StringBuilder sb;
    private static final int INF=(int)(1e8);
    private static void solve(int T) throws Exception
    {
        int i,N;
        String[] s=br.readLine().trim().split(" ");
        N=Integer.parseInt(s[0]);
        int Q=Integer.parseInt(s[1]);
        int[][] cost=new int[26][26];
        for(i=0;i<26;i++) Arrays.fill(cost[i], INF);
        for(i=0;i<26;i++) cost[i][i]=0;
        s=br.readLine().trim().split(" ");
        char[][] str=new char[N][];
        for(i=0;i<N;i++) str[i]=s[i].toCharArray();
        for(i=0;i<N;i++)
        {
            for(char x:str[i])
            {
                for(char y:str[i])
                {
                    if(x!=y) cost[x-'A'][y-'A']=cost[y-'A'][x-'A']=1;
                }
            }
        }
        for (int k = 0; k < 26; ++k)
        {
            for (i = 0; i < 26; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    cost[i][j] = Math.min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
        StringBuilder sb2=new StringBuilder();
        while (Q-->0)
        {
            s=br.readLine().trim().split(" ");
            int X=Integer.parseInt(s[0])-1;
            int Y=Integer.parseInt(s[1])-1;
            int ans=INF;
            for(char x:str[X])
            {
                for(char y:str[Y])
                {
                    ans = Math.min(ans, cost[x-'A'][y-'A']);
                    ans=Math.min(ans,cost[y-'A'][x-'A']);
                }
            }
            if(ans==INF) ans=-3;
            sb2.append(ans+2).append(" ");
        }
        sb.append("Case #").append(T).append(": ");
        sb.append(sb2).append("\n");
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
