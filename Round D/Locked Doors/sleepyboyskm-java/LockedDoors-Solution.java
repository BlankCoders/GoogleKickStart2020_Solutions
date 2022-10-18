import java.io.*;
import java.util.*;


public class Solution implements Runnable
{


    static Node[] tr;
    static class Node {
        int left, right, max;
        public Node(int l, int r, int m) {
            left = l;
            right = r;
            max = m;
        }
    }

    static void build(int root, int start, int end) {
        tr[root] = new Node(start, end, arr[start]);
        if (start == end) return;
        int mid = start + end >> 1;
        build(root << 1, start, mid);
        build(root << 1 | 1, mid + 1, end);
        pushup(root);
    }

    static void pushup(int root) {
        pushup(tr[root], tr[root << 1], tr[root << 1 | 1]);
    }

    static void pushup(Node root, Node l, Node r) {
        root.max = Math.max(l.max, r.max);
    }

    static int query(int root, int start, int end) {
        if (start > end) return 0;
        if (tr[root].left >= start && tr[root].right <= end) return tr[root].max;
        int mid = tr[root].left + tr[root].right >> 1;
        if (mid >= end) return query(root << 1, start, end);
        if (mid < start) return query(root << 1 | 1, start, end);

        int left = query(root << 1, start, mid);
        int right = query(root << 1 | 1, mid + 1, end);
        return Math.max(left, right);
    }

    @Override
    public void run() {
        InputReader in = new InputReader(System.in);
        w = new PrintWriter(System.out);
        T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            N = in.nextInt();
            Q = in.nextInt();
            arr = new int[N + 1];
            tr = new Node[4 * N];
            for (int i = 1; i < N; i++) {
                arr[i] = in.nextInt();
            }
            arr[0] = Integer.MAX_VALUE;
            arr[N] = Integer.MAX_VALUE;
            build(1, 1, N - 1);
            List<Integer> list = new ArrayList<>();
            for (int q = 0; q < Q; q++) {
                s = in.nextInt();
                k = in.nextInt();
                list.add(getRes());
            }
            w.print("Case #" +  t +  ": ");
            for (int num : list) {
                w.print(num + " ");
            }
            w.println();
        }

        w.flush();
        w.close();
    }

    static PrintWriter w;
    static int T, N, Q, s, k;
    static int[] arr;

    static int getRes() {
        if (k == 1) return s;
        if (k == 2) {
            if (s == 1) return 2;
            if (s == N) return N - 1;
            return arr[s - 1] > arr[s] ? s + 1 : s - 1;
        }
        int left = Math.max(1, s - k + 2), right = s;
        while (left < right) {
            int mid = left + right >> 1;
            int end = mid + k - 2;
            if (end > N) {
                right = mid - 1;
                continue;
            }

            int l = mid == 1 ? Integer.MAX_VALUE : arr[mid - 1];
            int r = end == N ? Integer.MAX_VALUE : arr[end];
            int maxL = query(1, mid, s - 1);
            int maxR = query(1, s, end - 1);
            if (maxL < maxR && l < maxR) {
                right = mid - 1;
            }
            else if (r < maxL && maxR < maxL) {
                left = mid + 1;
            }
            else {
                left = mid;
                break;
            }
        }

        right = left + k - 2;
        if (left == 1) return right + 1;
        if (right == N) return left - 1;
        return arr[left - 1] > arr[right] ? right + 1 : left - 1;
    }


    static class InputReader
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
        private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        public InputReader(InputStream stream)
        {
            this.stream = stream;
        }

        public int read()
        {
            if (numChars==-1)
                throw new InputMismatchException();

            if (curChar >= numChars)
            {
                curChar = 0;
                try
                {
                    numChars = stream.read(buf);
                }
                catch (IOException e)
                {
                    throw new InputMismatchException();
                }

                if(numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
        public int nextInt()
        {
            int c = read();

            while(isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-')
            {
                sgn = -1;
                c = read();
            }

            int res = 0;
            do
            {
                if(c<'0'||c>'9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public long nextLong()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            long res = 0;

            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.')
            {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, nextInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.')
            {
                c = read();
                double m = 1;
                while (!isSpaceChar(c))
                {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, nextInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public String readString()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = read();
            }
            while (!isSpaceChar(c));

            return res.toString();
        }

        public boolean isSpaceChar(int c)
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next()
        {
            return readString();
        }

        public interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);
        }
    }

    public static void main(String args[]) throws Exception
    {
        new Thread(null, new Solution(),"Main",1<<27).start();
    }

}
