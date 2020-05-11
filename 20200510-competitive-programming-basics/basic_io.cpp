#include <bits/stdc++.h>

using namespace std;

/*
 * Sort a sequence in non-decreasing order.
 * Just to show how to IO in CP contests.
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &val : a) {
            cin >> val;
        }
        sort(a.begin(), a.end());
        for (int val : a) {
            cout << val << ' ';
        }
        cout << '\n';
    }
    return 0;
}
/*
Input:
3
5
1 2 3 4 5
5
5 4 3 2 1
3
2 1 3

Output:
1 2 3 4 5
1 2 3 4 5
1 2 3
*/
