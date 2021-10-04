#include <bits/stdc++.h>

using namespace std;

/**
 * Each operation (method) takes O(alpha(n)) time -> Ackermann's function (Math)
 * This is almost constant, grows insanely slow
 * Path Compression Optimization with Ranking (by Size)
 */
class dsu {

private:

    // Data Members
    int n;  // Number of vertices
    int components;  // Number of components

    vector<int> parent;  // ID of a vertex's component
    vector<int> size;  // Size of a vertex's component

public:

    // Member functions/methods
    inline dsu(const int _n) /* : n(_n), components(_n), parent(_n), size(_n, 1) */ {
        // iota(parent.begin(), parent.end(), 0);  // std::iota is present in <numeric> library
        // it will fill parent array and make it [0, 1, 2, ..., n - 1], 0 being the initial value
        n = _n;
        components = n;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    /**
     * returns the ID of the component which v belongs to
     */
    int get_parent(const int v) {
        // return v == parent[v] ? v : (parent[v] = get_parent(parent[v]));
        if (v == parent[v]) {
            return v;
        }
        parent[v] = get_parent(parent[v]);  // Path Compression
        return parent[v];
    }

    /**
     * unites u's and v's components
     * returns true if they (u and v) initially belonged to different components (actual unification)
     * the same can also be achieved by checking if get_parent(u) == get_parent(v)
     */
    bool unite(int u, int v) {
        int p_u = get_parent(u);
        int p_v = get_parent(v);
        if (p_u == p_v) {
            return false;
        }
        // Ranking by Size
        if (size[p_v] > size[p_u]) {
            swap(u, v);
            swap(p_u, p_v);
        }
        size[p_u] += size[p_v];
        parent[p_v] = p_u;
        components--;
        return true;
    }

    inline int get_n() const {
        return n;
    }

    inline int get_components() const {
        return components;
    }

    /**
     * get size of the component which v belongs to
     */
    int get_size(const int v) {
        return size[get_parent(v)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, queries;
        cin >> n >> queries;
        dsu d(n);
        cout << d.get_components() << '\n';
        while (queries--) {
            int u, v;
            cin >> u >> v; u--; v--;
            d.unite(u, v);
            cout << d.get_components() << '\n';
        }
    }
    return 0;
}
