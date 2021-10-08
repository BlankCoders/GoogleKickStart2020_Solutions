import java.util.Scanner;

public class High_Buildings {

    public static void solve(int n, int a, int b, int c) {

        if (n == 1) {
            if (a == 1 && b == 1 && c == 1) {
                System.out.println("1");
                return;
            } else {
                System.out.println("IMPOSSIBLE");
                return;
            }
        } else if (n == 2) {
            if (a == 2 && b == 2 && c == 2) {
                System.out.println("1 1");
                return;
              
            } else if (a == 2 && b == 1 && c == 1) {
                System.out.println("1 2");
                return;
               
            } else if (a == 1 && b == 2 && c == 1) {
                System.out.println("2 1");
                return;
                
            } else {
                System.out.println("IMPOSSIBLE");
                return;
                
            }
        } else {
            int left = (n - (a + b - c));
            if (left < 0) {
                System.out.println("IMPOSSIBLE");
                return;
                
            }
            if ((a - c) > 0) {
                for (int i = 0; i < (a - c); i++)
                    System.out.print("2 ");

                for (int i = 0; i < left; i++)
                    System.out.print("1 ");

                for (int i = 0; i < c; i++)
                    System.out.print("3 ");

                for (int i = 0; i < (b - c); i++)
                    System.out.print("2 ");
            } else if ((b - c ) > 0) {
                for (int i = 0; i < (a - c); i++)
                    System.out.print("2 ");

                for (int i = 0; i < c; i++)
                    System.out.print("3 ");

                for (int i = 0; i < left; i++)
                    System.out.print("1 ");

                for (int i = 0; i < (b - c); i++)
                    System.out.print("2 ");
            } else if (c >= 2) {
                System.out.print("3 ");

                for (int i = 0; i < left; i++)
                    System.out.print("1 ");

                for (int i = 0; i < (c - 1); i++)
                    System.out.print("3 ");
            } else {
                System.out.println("IMPOSSIBLE");
                return;
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 1; i <= t; i++) {
            int n, a, b, c;
            n = sc.nextInt();
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            System.out.print("Case #" + i + ": ");
            solve(n, a, b, c);
        }
        sc.close();
    }
}