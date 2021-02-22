import java.util.Scanner;

public class Workout {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCasesNumber = in.nextInt();
        for (int i = 0; i < testCasesNumber; i++){
            int n = in.nextInt();
            int k = in.nextInt();
            int[] minutes = new int[n];
            for (int training = 0; training < n; training++){
                minutes[training] = in.nextInt();
            }
            System.out.printf("Case #%d: %d\n", i + 1, minDifficulty(minutes, n, k));
        }
    }

    public static int minDifficulty(int[] minutes, int n, int k){
        int maxDifference = minutes[n - 1] - minutes[0];
        int minDifference = 1;
        // using binary search to find appropriate minimum difference,
        // so that we have enough trainings (k) to obtain this difference
        while (minDifference < maxDifference){
            int midDifference = (minDifference + maxDifference) / 2;
            int kNeeded = 0;
            for (int i = 1; i < n; i++){
                int difference = minutes[i] - minutes[i - 1];
                kNeeded += (difference - 1) / midDifference;
            }
            if (kNeeded <= k){
                maxDifference = midDifference;
            }
            else {
                minDifference = midDifference + 1;
            }
        }
        return minDifference;
    }
}
