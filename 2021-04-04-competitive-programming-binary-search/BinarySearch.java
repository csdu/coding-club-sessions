import java.util.Scanner;

public class BinarySearch {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = input.nextInt();
        }
        int k = input.nextInt();

        /*
         * Given that a[0] <= a[1] <= ... <= a[n - 1]
         * Sorted in non-decreasing order
         * Check whether `k` exists in `a` or not
         */

        System.out.println(doesExist(a, k) ? "YES" : "NO");
        input.close();
    }

    private static boolean doesExist(int[] a, int toFind) {
        int low = 0, high = a.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] == toFind) {
                return true;
            }
            if (a[mid] > toFind) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
}
