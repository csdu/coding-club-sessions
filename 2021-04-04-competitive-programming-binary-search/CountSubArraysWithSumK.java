import java.util.Scanner;

public class CountSubArraysWithSumK {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = input.nextInt();
        }
        int k = input.nextInt();

        /*
         * The sequence `a` can be in any random order
         * a[i] >= 1 for all `i`
         * This implies, `Prefix Sums` will be "strictly increasing"
         *
         * We have to count all `sub arrays` which have sum `k`
         */

        // Prefix Sums Array: prefix[i + 1] = sum of range [0; i]
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + a[i];
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            long toFind = prefix[i] + k;
            if (existsPrefixSum(prefix, toFind, i + 1)) {
                answer++;
            }
        }
        System.out.println(answer);
        input.close();
    }

    private static boolean existsPrefixSum(long[] prefix, long toFind, int startFrom) {
        int low = startFrom, high = prefix.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (prefix[mid] == toFind) {
                return true;
            }
            if (prefix[mid] > toFind) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
}

/*
 * This solution works in O(n log n) time
 * Although, we have another method available (known as "Two Pointers Method")
 * which solves the same problem in O(n) time
 */
