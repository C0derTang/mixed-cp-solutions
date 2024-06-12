#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

struct DSU {
    vector<int> roots;
    vector<int> sizes;

    void init(int n) {
        roots = vector<int>(n);
        sizes = vector<int>(n, 1);
        for (int i = 0; i < n; ++i) roots[i] = i;
    }

    int find(int x) {
        return roots[x] == x ? x : (roots[x] = find(roots[x]));
    }

    bool unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return false;
        if (sizes[rx] < sizes[ry]) swap(rx, ry);
        sizes[rx] += sizes[ry];
        roots[ry] = rx;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> ids(n, vector<int>(m, -1));
    int cellCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                ids[i][j] = cellCount++;
            }
        }
    }

    DSU dsu;
    dsu.init(cellCount);

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '#') {
                        dsu.unite(ids[i][j], ids[ni][nj]);
                    }
                }
            }
        }
    }

    vector<int> compsizes(cellCount, 0);
    for (int i = 0; i < cellCount; ++i) {
        compsizes[dsu.find(i)]++;
    }

    int maxArea = 0;

    for (int i = 0; i < n; ++i) {
        int curArea = 0;
        unordered_set<int> comps;
        for (int j = 0; j < m; ++j) {
            if (i > 0 && grid[i - 1][j] == '#') comps.insert(dsu.find(ids[i - 1][j]));
            if (grid[i][j] == '#') comps.insert(dsu.find(ids[i][j]));
            if (i < n - 1 && grid[i + 1][j] == '#') comps.insert(dsu.find(ids[i + 1][j]));
            if (grid[i][j] == '.') curArea++;
        }
        for (auto comp : comps) {
            curArea += compsizes[comp];
        }
        maxArea = max(maxArea, curArea);
    }

    for (int j = 0; j < m; ++j) {
        int curArea = 0;
        unordered_set<int> comps;
        for (int i = 0; i < n; ++i) {
            if (j > 0 && grid[i][j - 1] == '#') comps.insert(dsu.find(ids[i][j - 1]));
            if (grid[i][j] == '#') comps.insert(dsu.find(ids[i][j]));
            if (j < m - 1 && grid[i][j + 1] == '#') comps.insert(dsu.find(ids[i][j + 1]));
            if (grid[i][j] == '.') curArea++;
        }
        for (auto comp : comps) {
            curArea += compsizes[comp];
        }
        maxArea = max(maxArea, curArea);
    }

    cout << maxArea << '\n';
}


signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
