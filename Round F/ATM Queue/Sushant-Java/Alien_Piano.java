import java.util.*;
import java.io.*;
import java.util.stream.*;

public class Solution {

    private static final Scanner _in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    private static String solve() {
        final int N = _in.nextInt();
        final int X = _in.nextInt();

        int[] A = IntStream.range(0, N).map(i -> (int) Math.ceil(_in.nextInt() / (double) X)).toArray();

        return String.join(" ", IntStream.range(0, N).boxed().sorted((i, j) -> A[i] - A[j])
                .map(i -> Integer.toString(i + 1)).collect(Collectors.toList()));
    }

    public static void main(String[] args) {
        final int T = _in.nextInt();
        for (int i = 1; i <= T; ++i) {
            System.out.println("Case #" + i + ": " + solve());
        }
    }
}