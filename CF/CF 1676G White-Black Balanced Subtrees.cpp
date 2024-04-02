#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Adjacency list
string colors;
int balancedCount;

pair<int, int> dfs(int v) {
    int black = 0, white = 0;
    if (colors[v-1] == 'B') ++black; else ++white;

    for (int child : adj[v]) {
        auto [cBlack, cWhite] = dfs(child);
        black += cBlack;
        white += cWhite;
    }

    if (black == white) ++balancedCount;

    return {black, white};
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n+1, vector<int>());
    for (int i = 2; i <= n; ++i) {
        int parent;
        cin >> parent;
        adj[parent].push_back(i);
    }
    cin >> colors;

    balancedCount = 0;
    dfs(1);
    cout << balancedCount << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
