// Solution to: https://www.codechef.com/problems/PERCAPTA

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v; u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0); // numeric
        // for (int i = 0; i < n; i++) { order[i] = i; }
        sort(order.begin(), order.end(), [&](const int &i, const int &j) -> bool {
            return 1.0 * a[i] / b[i] > 1.0 * a[j] / b[j];
        });

        vector<bool> vis(n);
        vector<int> comp;

        long cap, pop;

        function<void(int)> dfs = [&](int u) -> void {
            vis[u] = true;
            if (pop == 0) {
                cap += a[u];
                pop += b[u];
            } else {
                double cur = 1.0 * (cap + a[u]) / (pop + b[u]);
                double prev = 1.0 * cap / pop;
                if (cur < prev) {
                    return;
                }
                cap += a[u];
                pop += b[u];
            }
            for (int v : g[u]) {
                if (!vis[v]) {
                    dfs(v);
                }
            }
            comp.push_back(u);
        };

        double opt = 0;
        vector<int> res;
        for (int i : order) {
            if (!vis[i]) {
                cap = pop = 0;
                comp.clear();
                dfs(i);
                if (1.0 * cap / pop < opt) {
                    break;
                }
                opt = 1.0 * cap / pop;
                if (comp.size() > res.size()) {
                    res.assign(comp.begin(), comp.end());
                }
            }
        }

        cout << res.size() << '\n';
        for (int v : res) {
            cout << v + 1 << ' ';
        }
        cout << '\n';

    }
    return 0;
}
