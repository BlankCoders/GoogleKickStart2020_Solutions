import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {
	static class LongSumTree {

		final long t[];

		LongSumTree(int n) {
			t = new long[n];
		}

		void init(long v[]) {
			int n = t.length;
			arraycopy(v, 0, t, 0, n);
			for (int i = 0, j; i < n; i++) {
				if ((j = i | (i + 1)) < n) {
					t[j] += t[i];
				}
			}
		}

		long getPrefixSum(int i) {
			long res = 0;
			for (; i > 0; i &= i - 1) {
				res += t[i - 1];
			}
			return res;
		}

		long get(int i) {
			return getPrefixSum(i + 1) - getPrefixSum(i);
		}

		long getSum(int l, int r) {
			return getPrefixSum(r) - getPrefixSum(l);
		}

		void add(int i, long v) {
			t[i] += v;
			while ((i |= i + 1) < t.length) {
				t[i] += v;
			}
		}

		void set(int i, long v) {
			add(i, v - get(i));
		}
	}

	static void solve() throws Exception {
		int n = scanInt(), q = scanInt();
		LongSumTree t1 = new LongSumTree(n), t2 = new LongSumTree(n);
		for (int i = 0; i < n; i++) {
			long v = scanLong();
			if ((i & 1) != 0) {
				v = -v;
			}
			t1.add(i, v);
			t2.add(i, i * v);
		}
		long ans = 0;
		for (int i = 0; i < q; i++) {
			switch (scanString()) {
			case "U":
			{
				int x = scanInt() - 1;
				long v = scanLong();
				if ((x & 1) != 0) {
					v = -v;
				}
				t1.set(x, v);
				t2.set(x, x * v);
			}
			break;
			case "Q":
			{
				int l = scanInt() - 1, r = scanInt();
				long s1 = t1.getSum(l, r);
				long s2 = t2.getSum(l, r);
				long v = s2 - (l - 1) * s1;
				if ((l & 1) != 0) {
					v = -v;
				}
				ans += v;
			}
			break;
			default:
				int x=1;
			}
		}
		printCase();
		out.println(ans);
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static void printCase() {
		out.print("Case #" + test + ": ");
	}

	static void printlnCase() {
		out.println("Case #" + test + ":");
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			int tests = scanInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}