
import java.util.*;


import java.io.*;


public class Solution {
    
    static int mod = (int) (1e9+7);
    static InputReader in;
    static PrintWriter out;
    
    static boolean apply(int[][] recipe, long[][] dp, int R, int N, int S) {
    	
    	int y = 1000;
    	boolean ok = false;
    	while(y-- > 0) {
    		boolean change = false;
	    	for(int i = 0; i < R; i++) {
	    		for(int j = 0; j < N; j++) {
	    			long sum = 0;
	    			for(int k = 0; k < recipe[i].length - 1; k++) {
	    				sum += dp[j][recipe[i][k]];
	    			}
	    			if(sum < dp[j][recipe[i][recipe[i].length - 1]]) {
	    				dp[j][recipe[i][recipe[i].length - 1]] = sum;
	    				change |= true;
	    			}
	    		}
	    	}
	    	ok |= change;
	    	if(!change) break;
    	}
    	return ok;
    }
    
    static void distance(long[][] dist, int V) {
    	for (int k = 0; k < V; k++) 
        { 
            for (int i = 0; i < V; i++) 
            { 
                for (int j = 0; j < V; j++) 
                { 
                    if (dist[i][k] + dist[k][j] < dist[i][j]) 
                        dist[i][j] = dist[i][k] + dist[k][j]; 
                } 
            } 
        }
    }
    
    static void solve()
    {
 
        in = new InputReader(System.in);
        out = new PrintWriter(System.out); 
        
        int t = in.nextInt();
    	long maxn = (long)1e12;

        for(int ta = 1; ta <= t; ta++){
        	int N = in.nextInt();
        	int M = in.nextInt();
        	int S = in.nextInt();
        	int R = in.nextInt();
        	
        	long[][] dist = new long[N][N];
        	for(int i = 0; i < N; i++) {
        		Arrays.fill(dist[i], maxn);
        		dist[i][i] = 0;
        	}
        	
        	for(int i = 0; i < M; i++) {
        		int u = in.nextInt() - 1;
        		int v = in.nextInt() - 1;
        		dist[u][v] = 1;
        		dist[v][u] = 1;
        	}
        	
        	long[][] dp = new long[N][S + 1];
        	for(int i = 0; i < N; i++) {
        		Arrays.fill(dp[i], maxn);
        	}
        	
        	for(int i = 0; i < N; i++) {
        		int c = in.nextInt();
        		for(int j = 0; j < c; j++) {
        			int x = in.nextInt();
        			dp[i][x] = 0;
        		}
        	}
        	
        	int[][] recipe = new int[R][];
        	
        	for(int i = 0; i < R; i++) {
        		int k = in.nextInt();
        		recipe[i] = new int[k + 1];
        		for(int j = 0; j < k + 1; j++) {
        			recipe[i][j] = in.nextInt();
        		}
        	}
        	
        	distance(dist, N);
        	
        	int y = 1000;
        	while(y -- > 0) {
        		boolean change = false;
	        	for(int i = 0; i < N; i++) {
	        		for(int j = 0; j < N; j++) {
	        			for(int k = 1; k <= S; k++) {
	        				if(dp[i][k] > dp[j][k] + dist[i][j]) {
	        					dp[i][k] = dp[j][k] + dist[i][j];
	        					change = true;
	        				}
	        			}
	        		}
	        	}
	        	change |= apply(recipe, dp, R, N, S);
	        	if(!change) break;
        	}
        	long ans = maxn;
        	for(int i = 0; i < N; i++) {
        		ans = min(ans, dp[i][1]);
        	}
        	if(ans >= maxn) ans = -1;
            out.println("Case #" + ta+": " + ans);
//            out.printf("Case #%d: %.6f\n",ta);
        }
        out.close();
        out.close();
        
    }
    
    public static void main(String[] args) {
        new Thread(null ,new Runnable(){
            public void run()
            {
                try{
                    solve();
                } catch(Exception e){
                    e.printStackTrace();
                }
            }
        },"1",1<<26).start();
    }
    
    static int[][] graph(int from[], int to[], int n)
    {
        int g[][] = new int[n][];
        int cnt[] = new int[n];
        for (int i = 0; i < from.length; i++) {
            cnt[from[i]]++;
            cnt[to[i]]++;
        }
        for (int i = 0; i < n; i++) {
            g[i] = new int[cnt[i]];
        }
        Arrays.fill(cnt, 0);
        for (int i = 0; i < from.length; i++) {
            g[from[i]][cnt[from[i]]++] = to[i];
            g[to[i]][cnt[to[i]]++] = from[i];
        }
        return g;
    }
    
    static class Pair implements Comparable<Pair>{

        int x,y,i;
        
		Pair (int x,int y,int i){
			this.x=x;
			this.y=y;
			this.i=i;
		}

		Pair (int x,int y){
			this.x=x;
			this.y=y;
		}
	        
		public int compareTo(Pair o) {
			return Integer.compare(this.y,o.y);
			//return 0;
		}

        public boolean equals(Object o) {
            if (o instanceof Pair) {
                Pair p = (Pair)o;
                return p.x == x && p.y == y && p.i==i;
            }
            return false;
        }
        public int hashCode() {
            return new Integer(x).hashCode() * 31 + new Integer(y).hashCode()+new Integer(i).hashCode()*37;
        }
        
        @Override
        public String toString() {
        	return x + " " + y;
        }
    
    } 
    
    static String rev(String s) {
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        return sb.toString();
    }

    static long gcd(long x, long y) {
        if (y == 0) {
            return x;
        } else {
            return gcd(y, x % y);
        }
    }

    static int gcd(int x, int y) {
        if (y == 0) {
            return x;
        } else {
            return gcd(y, x % y);
        }
    }
    
    static int abs(int a, int b) {
        return (int) Math.abs(a - b);
    }

    static long abs(long a, long b) {
        return (long) Math.abs(a - b);
    }

    static int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    static int min(int a, int b) {
        if (a > b) {
            return b;
        } else {
            return a;
        }
    }

    static long max(long a, long b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }

    static long min(long a, long b) {
        if (a > b) {
            return b;
        } else {
            return a;
        }
    }

    static long pow(long n, long p, long m) {
        long result = 1;
        if (p == 0) {
            return 1;
        }
        while (p != 0) {
            if (p % 2 == 1) {
                result *= n;
            }
            if (result >= m) {
                result %= m;
            }
            p >>= 1;
            n *= n;
            if (n >= m) {
                n %= m;
            }
        }
        return result;
    }

    static long pow(long n, long p) {
        long result = 1;
        if (p == 0) {
            return 1;
        }
        if (p == 1) {
            return n;
        }
        while (p != 0) {
            if (p % 2 == 1) {
                result *= n;
            }
            p >>= 1;
            n *= n;
        }
        return result;
    }
   
    static void debug(Object... o) {
            System.out.println(Arrays.deepToString(o));
    }

    static class InputReader
    {

        private final InputStream stream;
        private final byte[] buf = new byte[8192];
        private int curChar, snumChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream)
        {
                this.stream = stream;
        }

        public int snext()
        {
                if (snumChars == -1)
                        throw new InputMismatchException();
                if (curChar >= snumChars)
                {
                        curChar = 0;
                        try
                        {
                                snumChars = stream.read(buf);
                        } catch (IOException e)
                        {
                                throw new InputMismatchException();
                        }
                        if (snumChars <= 0)
                                return -1;
                }
                return buf[curChar++];
        }

        public int nextInt()
        {
                int c = snext();
                while (isSpaceChar(c))
                {
                        c = snext();
                }
                int sgn = 1;
                if (c == '-')
                {
                        sgn = -1;
                        c = snext();
                }
                int res = 0;
                do
                {
                        if (c < '0' || c > '9')
                                throw new InputMismatchException();
                        res *= 10;
                        res += c - '0';
                        c = snext();
                } while (!isSpaceChar(c));
                return res * sgn;
        }

        public long nextLong()
        {
                int c = snext();
                while (isSpaceChar(c))
                {
                        c = snext();
                }
                int sgn = 1;
                if (c == '-')
                {
                        sgn = -1;
                        c = snext();
                }
                long res = 0;
                do
                {
                        if (c < '0' || c > '9')
                                throw new InputMismatchException();
                        res *= 10;
                        res += c - '0';
                        c = snext();
                } while (!isSpaceChar(c));
                return res * sgn;
        }

        public int[] nextIntArray(int n)
        {
                int a[] = new int[n];
                for (int i = 0; i < n; i++)
                {
                        a[i] = nextInt();
                }
                return a;
        }

        public long[] nextLongArray(int n)
        {
                long a[] = new long[n];
                for (int i = 0; i < n; i++)
                {
                        a[i] = nextLong();
                }
                return a;
        }

        public String readString()
        {
                int c = snext();
                while (isSpaceChar(c))
                {
                        c = snext();
                }
                StringBuilder res = new StringBuilder();
                do
                {
                        res.appendCodePoint(c);
                        c = snext();
                } while (!isSpaceChar(c));
                return res.toString();
        }

        public String nextLine()
        {
                int c = snext();
                while (isSpaceChar(c))
                        c = snext();
                StringBuilder res = new StringBuilder();
                do
                {
                        res.appendCodePoint(c);
                        c = snext();
                } while (!isEndOfLine(c));
                return res.toString();
        }

        public boolean isSpaceChar(int c)
        {
                if (filter != null)
                        return filter.isSpaceChar(c);
                return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private boolean isEndOfLine(int c)
        {
                return c == '\n' || c == '\r' || c == -1;
        }

        public interface SpaceCharFilter
        {
                public boolean isSpaceChar(int ch);
        }

    }
}    

