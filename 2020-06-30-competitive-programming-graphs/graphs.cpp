#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m; // n vertices, m edges
    cin >> n >> m;

    vector<vector<int>> g(n);

    // m edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(n);
    vector<vector<int>> comp; // connected components of the graph

    /*
     * C++ Lambdas can't have default arguments. Also, for C++ Lambdas,
     * function overloading is not possible without using
     * "variable templates" (available since ISO C++14).
     */

    // Finding connected components in a graph.
    function<void(int)> dfs = [&](int u) -> void {
        vis[u] = true;
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
        comp.back().push_back(u);
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            comp.push_back(vector<int>());
            dfs(i);
        }
        // comp[i] is a vector containing the i-th connected component.
        // comp[i][j] is the j-th vertex (in some order) of the i-th component.
    }

    cout << "Number of connected components = " << comp.size() << '\n';

    // Detecting a cycle in an undirected graph.

    int cycle_undir = false;

    function<void(int, int)> dfs_undir = [&](int u, int p) -> void {
        vis[u] = true;
        for (int v : g[u]) {

            if (v == p) {
                continue;
            }

            if (vis[v]) {
                /*
                 * If there's a vertex which is visited and not a parent
                 * (or the vertex from which it came here) of the current
                 * vertex, then visiting it again forms a cycle in an
                 * undirected graph.
                 */
                cycle_undir = true; // cycle found
            } else {
                dfs_undir(v, u);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs_undir(i, -1);
        }
    }

    // Detecting a cycle in a directed graph.
    // [Note: For a directed graph, during input, line 19 will not be there.]

    /*
     * This method works for both directed and undirected graphs.
     * However, the previous cycle detection method (for undirected graphs)
     * doesn't work for directed graphs.
     */

    vector<int> col(n); // 0 -> unvisited,
                        // 1 -> visited but not completed (in progress),
                        // 2 -> visited and completed it's DFS.

    int cycle_dir = false;

    function<void(int)> dfs_dir = [&](int u) -> void {
        col[u] = 1;
        for (int v : g[u]) {

            if (col[v] == 1) {
                /*
                 * If we find a vertex which is still under progress
                 * (or hasn't yet completed it's DFS procedure), then this
                 * forms a cycle in a directed (even in an undirected) graph.
                 */
                cycle_dir = true;
            } else if (col[v] == 0) {
                dfs_dir(v);
            }
        }
        col[u] = 2; // vertex 'u' finished it's work (DFS).
    };

    for (int i = 0; i < n; i++) {
        if (col[i] == 0) {
            dfs_dir(i);
        }
    }

    return 0;
}
