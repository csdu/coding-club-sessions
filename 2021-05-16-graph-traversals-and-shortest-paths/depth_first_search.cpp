#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;
vector<int> a, subtree_v_cnt, subtree_sum, height, depth, path;
vector<vector<int>> g;

// Prints the `path` vector
void print_path() {
    cout << '[';
    bool first = true;
    for (int v : path) {
        if (!first) {
            cout << ", ";
        }
        cout << v;
        first = false;
    }
    cout << "]\n";
}

/**
 * A basic recursive definition, does many "subtree-based" properties,
 * computes them on the fly, and maintains valid states.
 */
void dfs(int vertex, int cur_depth, int path_sum) {
    visited[vertex] = true;
    subtree_v_cnt[vertex] = 1;
    subtree_sum[vertex] = a[vertex];
    height[vertex] = 1;
    depth[vertex] = cur_depth;

    path.push_back(vertex);

    bool is_leaf = true;
    for (int child : g[vertex]) {
        if (!visited[child]) {
            is_leaf = false;
            dfs(child, cur_depth + 1, path_sum + a[vertex]);
            subtree_v_cnt[vertex] += subtree_v_cnt[child];
            subtree_sum[vertex] += subtree_sum[child];
            height[vertex] = max(height[vertex], 1 + height[child]);
        }
    }

    // Prints all `root to leaf` paths in a rooted tree, along with their sum
    if (is_leaf) {
        cout << "Path: ";
        print_path();
        cout << "; Path Sum = " << (path_sum + a[vertex]) << endl;
    }
    path.pop_back();
}

// An iterative variant of DFS, simulated using a Stack
void iterative_dfs(int vertex) {
    stack<int> s;
    s.push(vertex);
    visited[vertex] = true;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        for (int child : g[cur]) {
            if (!visited[child]) {
                s.push(child);
                visited[child] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    a.resize(n);
    for (int &x : a) {
        cin >> x;
    }

    g.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    visited.resize(n);
    subtree_v_cnt.resize(n);
    subtree_sum.resize(n);
    height.resize(n);
    depth.resize(n);

    // Counting Connected Components along the way
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, 0, 0);
            components++;
        }
    }

    // Printing all computed properties
    for (int i = 0; i < n; i++) {
        cout << i << ": " << subtree_v_cnt[i] << ' ' << subtree_sum[i] << ' ' << height[i] << ' ' << depth[i] << '\n';
    }
    cout << '\n';
    cout << "Components: " << components << '\n';

    return 0;
}
