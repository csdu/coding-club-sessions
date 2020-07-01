#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; // vertices
    cin >> n;
    vector<vector<int>> g(n);

    // n - 1 edges
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Breadth First Search
    function<void(int)> &&bfs = [&](int u) -> void {
        queue<int> q;
        q.push(u);
        vector<bool> vis(n);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            vis[v] = true;

            /* some operation for a vertex */

            for (int ch : g[v]) {
                if (!vis[ch]) {
                    q.push(ch);
                }
            }
        }
    };

    bfs(0); // Calling BFS from Root of tree

    vector<int> color(n);
    vector<int> height(n), sub(n), white(n), black(n); // sub = sub tree size

    // C++ Lambdas can't have default arguments.
    function<void(int, int, int)> dfs = [&](int u, int depth, int p) -> void {
        int h = 0, s = 1;
        int w = (color[u] == 1);
        for (int v : g[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, depth + 1, u);
            /*
             * Height of a leaf is 0.
             * Height of any other vertex is 1 more than the maximum
             * height of it's child vertices.
             */
            h = max(1 + height[v], h);
            s += sub[v];
            w += white[v];
        }
        height[u] = h; // Here also, height of leaf will be 0.
                       // And follow the same as mentioned above for others.
        sub[u] = s;
        white[u] = w;
        black[u] = sub[u] - white[u];
    };

    dfs(0, 0, -1); // calling DFS from Root of tree

    return 0;
}
