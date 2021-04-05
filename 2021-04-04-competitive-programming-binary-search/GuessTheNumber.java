import java.util.Scanner;

// Guess the Number: https://codeforces.com/gym/101021/problem/1

public class GuessTheNumber {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        /*
         * Suppose the number chosen on Online Judge (OJ) is x = 75, then
         * [1; 74] are all less than x = 75, and
         * [75; 10^6] are all greater than or equal to x = 75
         *
         * Thus, this forms a similar boolean function of the form
         * f(1) f(2) ... f(74) f(75) f(76) ... f(10^6)
         *  0    0         0     1     1          1
         *
         * And we need to find the smallest function argument `k`
         * for which f(k) = 1 ("left most" 1)
         */

        int low = 1, high = 1_000_000, answer = high + 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (getQueryResponse(mid, input).equals("<")) {
                high = mid - 1;
            } else {
                answer = mid;
                low = mid + 1;
            }
        }
        reportResult(answer);
        input.close();
    }

    private static final int QUERY_LIMIT = 25;

    private static int queries = 0;

    private static String getQueryResponse(int guess, Scanner input) {
        queries++;
        if (queries > QUERY_LIMIT) {
            throw new AssertionError();
        }
        System.out.println(guess);
        return input.next();
    }

    private static void reportResult(int result) {
        System.out.println("! " + result);
    }
}
