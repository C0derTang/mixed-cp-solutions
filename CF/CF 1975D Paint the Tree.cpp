#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<bool> visited;

int maxlen(const vector<vector<int>>& adj, int cur, vector<bool>& visited) {
    int ret = 0;
    visited[cur] = true;
    for (auto x : adj[cur]) {
        if (!visited[x]) {
            ret = max(ret, maxlen(adj, x, visited));
        }
    }
    return ret + 1;
}

void solve() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    --a; --b;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int root = -1;
    int steps = 0;
    queue<int> patha, pathb;
    patha.push(a);
    pathb.push(b);

    vector<bool> seena(n, false);
    vector<bool> seenb(n, false);

    bool found = false;
    while (!found) {
        int s1 = patha.size();
        int s2 = pathb.size();

        for (int i = 0; i < s1; ++i) {
            int cur = patha.front();
            patha.pop();
            seena[cur] = true;
            for (auto x : adj[cur]) {
                if (!seena[x]) {
                    patha.push(x);
                }
            }
        }

        for (int i = 0; i < s2; ++i) {
            int cur = pathb.front();
            pathb.pop();
            if (seena[cur]) {
                root = cur;
                found = true;
                break;
            }
            seenb[cur] = true;
            for (auto x : adj[cur]) {
                if (!seenb[x]) {
                    pathb.push(x);
                }
            }
        }
        if (!found) ++steps;
    }

    vector<bool> visited(n, false);
    cout << steps + 2 * (n - 1) - maxlen(adj, root, visited) + 1 << '\n';
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
