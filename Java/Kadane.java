import java.util.*;
import java.io.*;

public class Kadane {

    public static class KadaneResponse {
        private int fromIndex, toIndex, sum;

        public KadaneResponse(int fromIndex, int toIndex, int sum) {
            this.fromIndex = fromIndex;
            this.toIndex = toIndex;
            this.sum = sum;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) arr[i] = in.nextInt();

        KadaneResponse k = Kadane(arr, N);

        System.out.print("Sum: " + k.sum  + " From: " + k.fromIndex  + " To: " + k.toIndex + "\n");
    }

    public static KadaneResponse Kadane(int[] a, int n) {
        int partialSum = a[0],
            bestSum = a[0],
            from = 0,
            to = 0,
            i;

        for(i = 1; i < n; ++i) {
            if(a[i] > partialSum + a[i]) {
                partialSum = a[i];
                from = i;
            } else {
                partialSum += a[i];
            }

            if(partialSum >= bestSum) {
                bestSum = partialSum;
                to = i;
            }
        }

        return new KadaneResponse(from, to, bestSum);
    }
}