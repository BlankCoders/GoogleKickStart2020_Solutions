import java.io.*;
import java.util.*;

public class Alien_piano {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int n = in.nextInt(), i = 0, pre = -1, cnt = 0, ans = 0;
            for (i = 0; i < n; i++) {
                int cur = in.nextInt();
                if (i > 0) {
                    if (cur > pre) {
                        if (cnt == 4) {
                            ++ans;
                            cnt = 1;
                        } else if (cnt <= 0) {
                            cnt = 2;
                        } else {
                            ++cnt;
                        }
                    } else if (cur < pre) {
                        if (cnt == -4) {
                            ++ans;
                            cnt = -1;
                        } else if (cnt >= 0) {
                            cnt = -2;
                        } else {
                            --cnt;
                        }
                    }
                }
                pre = cur;
            }
            System.out.println("Case #" + t + ": " + ans);
        }
    }
}