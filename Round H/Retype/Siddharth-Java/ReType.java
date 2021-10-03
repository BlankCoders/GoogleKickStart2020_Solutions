//took help from a college senior
import java.util.*;
import java.io.*;

public class Solution {

    private static final Scanner _in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    private static int solve() {
        int N = _in.nextInt();
        int K = _in.nextInt();
        int S = _in.nextInt();

        return (K-1) + Math.min(S, K-S) + (N-S+1);
    }

    public static void main(String[] args) {
        int T = _in.nextInt();
        for (int i = 1; i <= T; ++i) {
            System.out.println("Case #" + i + ": " + solve());
        }
    }
}