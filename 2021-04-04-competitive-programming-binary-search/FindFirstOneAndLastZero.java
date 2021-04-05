import java.util.Scanner;

public class FindFirstOneAndLastZero {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = input.nextInt();
        }

        /*
         * a[i] is either 0 or 1
         * `a` is of the form 00000000000.....0111111111111111111.....1
         * Starts with some `x` 0s and ends with some `y` 1s
         * x >= 0 and y >= 0
         */

        System.out.println(findFirstOne(a));
        System.out.println(findLastZero(a));
        input.close();
    }

    // Return index is 1-based
    private static int findFirstOne(int[] a) {
        int low = 0, high = a.length - 1, answer = a.length + 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] == 1) {
                answer = mid + 1;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }

    // Return index is 1-based
    private static int findLastZero(int[] a) {
        int low = 0, high = a.length - 1, answer = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] == 0) {
                answer = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
}
