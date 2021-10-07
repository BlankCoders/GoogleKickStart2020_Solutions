import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            int N;
            long D;
            N = sc.nextInt();
            D = sc.nextLong();
            long a[] = new long[N];
            for (int j = 0; j < N; j++) {
                a[j] = sc.nextLong();
            }
            Long latest = D;
            for (int k = N - 1; k >= 0; k--) {
                latest = Math.min(latest, latest - (latest % a[k]));
            }
            System.out.printf("Case #%d: %d\n", i, latest);
        }
    }
}