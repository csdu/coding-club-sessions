// Solution to https://www.codechef.com/problems/WEIRD2

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        int ans = 0;
        for (pair<const int, int> &p : mp) {
            int a = p.first;
            int count = p.second;
            for (int b = 1; b <= count; b++) {
                unordered_map<int, int>::iterator it = mp.find(b);
                if (it == mp.end()) {
                    continue;
                }
                if (it->second >= a) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
