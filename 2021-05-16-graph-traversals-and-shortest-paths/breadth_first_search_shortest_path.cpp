#include <bits/stdc++.h>

using namespace std;

void bfs_shortest_path(vector<vector<int>> &g, vector<bool> &vis, int start, int end) {
    queue<int> q;
    q.push(start);
    q.push(-1);
    vis[start] = true;
    int depth = 0, v_cnt_at_each_level = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == -1) {
            cout << "Count: " << v_cnt_at_each_level << '\n';
            depth++;
            v_cnt_at_each_level = 0;
            if (!q.empty()) {
                q.push(-1);
            }
            continue;
        }
        if (v_cnt_at_each_level == 0) {
            depth++;
        }
        v_cnt_at_each_level++;
        if (cur == end) {
            cout << "Distance from " << start << " to " << end << " = " << depth << '\n';
        }
        for (int child : g[cur]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = true;
            }
        }
    }
    cout << '\n';
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n);
    bfs_shortest_path(g, vis, 0, n - 1);

    return 0;
}
