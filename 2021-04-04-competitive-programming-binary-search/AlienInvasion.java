import java.util.Arrays;
import java.util.Scanner;

// Alien Invasion: https://www.codechef.com/problems/ALIENIN

public class AlienInvasion {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int tests = input.nextInt();
        while (tests-- > 0) {
            int n = input.nextInt(), d = input.nextInt();
            int[] c = new int[n];
            for (int i = 0; i < n; i++) {
                c[i] = input.nextInt();
            }

            /*
             * The sequence `c` can be in any order, so we need to sort it
             * as it represents entry times of the alien spaceships.
             */

            Arrays.sort(c);

            /*
             * How did we choose `high = 2 x 10^9`?
             * Suppose D = MAX = 10^9, and
             * C = [1, MAX], therefore existence times for the respective
             * alien spaceships are: [[1, 1 + MAX], [MAX, MAX + MAX]]
             *
             * So, at most, we can have a kill gap of (2 x MAX - 1)
             * Therefore, our answer lies somewhere in (0; 2 x 10^9)
             *
             * At most 51 (31 + 20 or (log2(2 x 10^9) +  log2(10^6)) iterations
             * of our Binary Search will let us achieve our answer with
             * the required precision
             *
             * Our Solution:
             * We can observe that if it is `feasible` to kill all alien spaceships
             * with a `coolDown` time `x`, then we can "always" kill all alien
             * spaceships for all `coolDown` times `k` in [0; x)
             *
             * And, similarly, we can also observe that if it is `infeasible` to
             * kill all alien spaceships with a `coolDown` time `x`, then
             * we can "never" kill all alien spaceships for all
             * `coolDown` times `k` in (x; inf)
             *
             * Thus, we have a similar boolean function on `coolDown` times `k`
             * f(k) = 1 for all k in [0; x], and
             * f(k) = 0 for all k in (x; inf)
             *
             * Here, he function `f` denotes `feasibility` of a `coolDown` time, and
             * `x` denotes the largest possible `coolDown` time,
             * which is what we need to find
             *
             * Remember, `coolDown` time is a real number, not an integer
             */

            // The form `low + EPSILON <= high` helps us in bounding our error by `EPSILON`
            // Precisely, it gives us a precision of at least (-log10(`EPSILON`) - 1)
            // digits after the decimal point.
            double low = 0.0, high = 2e9;
            while (low + 1e-6 <= high) {
                double mid = 0.5 * (low + high);
                if (isFeasible(c, d, mid)) {
                    low = mid;
                    // Range selections:
                    // (mid; inf) - for integers
                    // [mid; inf) - for floats / doubles / reals
                } else {
                    high = mid;
                }
            }

            // Prints a fixed floating point value with 6 digits of precision
            // after the decimal point
            System.out.printf("%.6f%n", 0.5 * (low + high));
        }
        input.close();
    }

    private static boolean isFeasible(int[] c, int d, double coolDown) {
        double timeElapsed = 0.0, previousKillTime = c[0] - coolDown;
        for (int arrivalTime : c) {
            if (arrivalTime > timeElapsed) {
                timeElapsed = arrivalTime;
            }
            double killTime = Math.max(previousKillTime + coolDown, timeElapsed);
            int alienEndTime = arrivalTime + d;
            if (killTime > alienEndTime) {
                return false;
            }
            previousKillTime = timeElapsed = killTime;
        }
        return true;
    }
}
