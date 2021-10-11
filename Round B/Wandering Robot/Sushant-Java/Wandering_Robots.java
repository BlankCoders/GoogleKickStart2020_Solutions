import java.io.*;
import java.util.Scanner;

class Wandering_Robots {
    public static void main(String[] args) throws FileNotFoundException {
        int t = 0, T = 0, W = 0, H = 0, L = 0, U = 0, R = 0, D = 0, i = 0, j = 0;
        double answer = 0.0;
        Scanner sc = new Scanner(System.in);

        T = sc.nextInt();
        for (t = 1; t <= T; t++) {
            answer = 1.0;
            W = sc.nextInt();
            H = sc.nextInt();
            L = sc.nextInt();
            U = sc.nextInt();
            R = sc.nextInt();
            D = sc.nextInt();
            if ((L == 1 && U == 1) || (R == W && D == H)) {
                System.out.println("Case #" + t + ": 0.0");
                continue;
            }
            double[][] dp = new double[W + 1][H + 1];
            dp[1][1] = 1.0;
            for (i = 1; i <= W; i++) {
                for (j = 1; j < U; j++) {
                    if (i == 1 && j == 1) {
                        continue;
                    }
                    if (i == W) {
                        dp[i][j] += dp[i][j - 1];
                    } else {
                        dp[i][j] += dp[i][j - 1] / 2;
                    }
                    if (j == H) {
                        dp[i][j] += dp[i - 1][j];
                    } else {
                        dp[i][j] += dp[i - 1][j] / 2;
                    }
                }
            }
            for (i = 1; i < L; i++) {
                for (j = U; j <= H; j++) {
                    if (i == 1 && j == 1) {
                        continue;
                    }
                    if (i == W) {
                        dp[i][j] += dp[i][j - 1];
                    } else {
                        dp[i][j] += dp[i][j - 1] / 2;
                    }
                    if (j == H) {
                        dp[i][j] += dp[i - 1][j];
                    } else {
                        dp[i][j] += dp[i - 1][j] / 2;
                    }
                }
            }
            if (L == W) {
                dp[L][U] += dp[L][U - 1];
            } else {
                dp[L][U] += dp[L][U - 1] / 2;
            }
            if (U == H) {
                dp[L][U] += dp[L - 1][U];
            } else {
                dp[L][U] += dp[L - 1][U] / 2;
            }
            answer -= dp[L][U];
            if (U > 1) {
                for (i = L + 1; i <= R; i++) {
                    if (i == W) {
                        dp[i][U] += dp[i][U - 1];
                    } else {
                        dp[i][U] += dp[i][U - 1] / 2;
                    }
                    answer -= dp[i][U];
                }
            }
            if (L > 1) {
                for (j = U + 1; j <= D; j++) {
                    if (j == H) {
                        dp[L][j] += dp[L - 1][j];
                    } else {
                        dp[L][j] += dp[L - 1][j] / 2;
                    }
                    answer -= dp[L][j];
                }
            }

            System.out.println("Case #" + t + ": " + answer);
        }
        sc.close();
    }
}
