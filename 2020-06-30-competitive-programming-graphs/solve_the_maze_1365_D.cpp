// Solution to: https://codeforces.com/contest/1365/problem/D

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #include "debug.hpp"
#else
    #define debug(...)
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        //           R  D  L   U
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};


        function<bool(int, int)> &&valid = [&](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'B') {
                    for (int k = 0; k < 4; k++) {
                        int xx = i + dx[k];
                        int yy = j + dy[k];
                        if (valid(xx, yy) && a[xx][yy] == '.') {
                            a[xx][yy] = '#';
                        }
                    }
                }
            }
        }


        vector<vector<bool>> can(n, vector<bool>(m));
        vector<vector<bool>> vis(n, vector<bool>(m));


        function<void(int, int)> dfs = [&](int x, int y) -> void {
            if (vis[x][y]) {
                return;
            }
            if (a[x][y] == '#') {
                return;
            }
            vis[x][y] = true;
            can[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (valid(xx, yy) && a[xx][yy] != '#') {
                    dfs(xx, yy);
                }
            }
        };

        dfs(n - 1, m - 1);

        bool poss = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'G' && !can[i][j]) {
                    poss = false;
                } else if (a[i][j] == 'B' && can[i][j]) {
                    poss = false;
                }
            }
        }

//        debug(a, can);

        cout << (poss ? "Yes\n" : "No\n");

    }
    return 0;
}
