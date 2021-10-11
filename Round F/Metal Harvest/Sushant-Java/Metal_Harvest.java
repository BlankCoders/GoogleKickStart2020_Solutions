import java.util.*;

class Pair {
    public long first, second;

    void setValue(long a, long b) {
        this.first = a;
        this.second = b;
    }

    void getValue() {
        System.out.println("first = " + this.first);
        System.out.println("second = " + this.second);
    }
}

class PairComparator implements Comparator<Pair> {
    public int compare(Pair o1, Pair o2) {
        Long x1 = o1.first;
        Long x2 = o2.first;
        return x1.compareTo(x2);
    }
}

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int k = 1; k <= T; k++) {
            long temp1, temp2;

            int n = sc.nextInt();
            int x = sc.nextInt();

            long sum = 0;
            Vector<Pair> A = new Vector<Pair>();

            for (int i = 0; i < n; i++) {
                Pair pair = new Pair();
                temp1 = sc.nextInt();
                temp2 = sc.nextInt();
                pair.setValue(temp1, temp2);
                A.add(pair);
            }


            Comparator<Pair> comparator = new PairComparator();
            Collections.sort(A, comparator);

            long cur = (A.get(0).first) + x;
            sum++;

            for (int i = 0; i < A.size(); i++) {
                if ((A.get(i).first) >= cur) {
                    cur = (A.get(i).first) + x;
                    sum++;
                }
                if ((A.get(i).second) > cur) {
                    while ((A.get(i).second) > cur) {
                        sum++;
                        cur += x;
                    }
                }
            }
            System.out.println("Case #" + k + ": " + sum);
        }
        sc.close();
    }
}

// https://www.youtube.com/watch?v=swVBW_faUoc