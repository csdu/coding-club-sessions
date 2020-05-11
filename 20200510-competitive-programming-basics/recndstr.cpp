// Solution to https://www.codechef.com/problems/RECNDSTR

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        // V = R(S); V = L(S)
        // => R(S) = L(S)
        if (s.back() + s.substr(0, (int) s.size() - 1) == s.substr(1) + s[0]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
