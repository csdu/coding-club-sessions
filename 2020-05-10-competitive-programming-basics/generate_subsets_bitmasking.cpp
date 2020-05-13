/*
 * Generating all subsets for a given set of size n.
 * We have use a technique called as "Bit Masking", where
 * we mask our problem on bits. So we represent a set of size n
 * as a bit string (or binary representation of a number) of length n
 * (n bits). Each bit's state signifies whether the element at this position
 * in the array will be included in the current subset or not. 0 for exclusion,
 * 1 for inclusion.
 */
#include <bits/stdc++.h>

using namespace std;

// n-set => 2^n subsets
int main() {
    vector<int> a = {1, 2, 3};
    int n = (int) a.size();
    // Iterate over all numbers from 0 to (2^n - 1)
    // Notice, these are all n bit numbers. Maximum value that an n bit
    // number can store is (2^n - 1).
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << '{';
        for (int i = 0; i < n; i++) {
            // Check whether i-th bit is on, if it is, include this element to
            // the current subset being processed.
            if (mask & (1 << i)) {
                cout << a[i] << ", ";
            }
        }
        cout << "}\n";
    }
    return 0;
}

/*
Output:

{}
{1, }
{2, }
{1, 2, }
{3, }
{1, 3, }
{2, 3, }
{1, 2, 3, }
*/
