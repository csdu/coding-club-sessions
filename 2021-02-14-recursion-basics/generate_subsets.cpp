#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets;
vector<int> subset;

/*
 * Follows Depth First Search (DFS) Strategy.
 * Recursively generates all subsets of a set.
 * Follows Inclusion-Exclusion technique.
 */
void generate_subsets(const int i, const vector<int> &a) {
    if (i == (int) a.size()) {
        subsets.push_back(subset);
        return;
    }

    // Inclusion
    subset.push_back(a[i]);
    generate_subsets(i + 1, a);

    // Exclusion
    subset.pop_back();
    generate_subsets(i + 1, a);
}

/*
 * Iteratively generates all subsets of a set, and prints them.
 * Uses the well known technique of "Bit Masking".
 *
 * Generating all subsets for a given set of size n.
 * We make use of a technique called as "Bit Masking", where
 * we mask our problem on bits. So we represent a set of size n
 * as a bit string (or binary representation of a number) of length n
 * (n bits). Each bit's state signifies whether the element at this position
 * in the array will be included in the current subset or not. 0 for exclusion,
 * 1 for inclusion.
 */
inline void print_subsets_iteratively(const vector<int> &a) {
    const int n = (int) a.size();
    /*
     * n-set => 2^n subsets
     * Iterate over all numbers from 0 to (2^n - 1)
     * Notice, these are all n bit numbers. Maximum value that an n bit
     * number can store is (2^n - 1).
     */
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << '{';
        for (int i = 0; i < n; i++) {
            /*
             * Check whether i-th bit is on, if it is, include this element to
             * the current subset being processed.
             */
            if (mask & (1 << i)) {
                cout << a[i] << ", ";
            }
        }
        cout << '}' << endl;
    }
}

int main() {
    vector<int> a = {1, 2, 3};
    generate_subsets(0, a);

    cout << "Generating subsets using recursion:" << endl;

    // Printing all generated subsets
    for (const vector<int> &s : subsets) {
        cout << '[';
        for (const int x : s) {
            cout << x << ' ';
        }
        cout << ']' << endl;
    }
    cout << endl;

    cout << "Generating subsets iteratively:" << endl;
    print_subsets_iteratively(a);
    return 0;
}
