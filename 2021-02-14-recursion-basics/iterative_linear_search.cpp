#include <iostream>
#include <vector>

using namespace std;

// Simple Iterative Linear Search
inline bool linear_search(const vector<int> &a, const int k) {
    for (const int value : a) {
        if (value == k) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    if (linear_search(a, k)) {
        cout << "FOUND!" << endl;
    } else {
        cout << "NOT FOUND!" << endl;
    }

    return 0;
}

/*
 * Inputs:
 * 5 4
 * 1 2 3 4 5
 *
 * 5 8
 * 1 2 3 4 5
 */
