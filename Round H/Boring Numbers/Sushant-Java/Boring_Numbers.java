import java.util.*;

public class Solution {

    public static long five[] = new long[20];
    public static long pre[] = new long[20];

    public static class Helper {
        int a[] = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4 };
        int b[] = { 0, 1, 1, 2, 2, 3, 3, 4, 4, 5 };

        public long count(long x) {
            String s = Long.toString(x);
            int n = s.length();
            char s1[] = s.toCharArray();
            long ans = pre[n - 1];

            for (int i = 1; i <= n; ++i) {
                int c = s1[i - 1] - '0';
                if (c % 2 != i % 2) {
                    ans += five[n - i] * b[c];
                    break;
                } else {
                    ans += five[n - i] * a[c];
                    if (i == n)
                        ans++;
                }
            }
            return ans;
        }

        public void solve(int case_num, long L, long R) {
            System.out.printf("Case #%d: %d\n", case_num, count(R) - count(L - 1));
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        five[0] = (long) 1;

        for (int i = 1; i < 20; ++i) {
            five[i] = five[i - 1] * 5;
        }

        pre[0] = (long) 0;

        for (int i = 1; i < 20; ++i) {
            pre[i] = pre[i - 1] + five[i];
        }

        for (int i = 1; i <= t; ++i) {
            Helper h = new Helper();
            long l = sc.nextLong();
            long r = sc.nextLong();
            h.solve(i, l, r);
        }
    }
}
