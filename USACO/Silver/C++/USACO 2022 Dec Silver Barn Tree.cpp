#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> h(n);
    int target = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        target += h[i];
    }
    target /= n;

    vector<unordered_set<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].insert(v - 1);
        adj[v - 1].insert(u - 1);
    }

    unordered_set<int> leefz;
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() == 1) leefz.insert(i);
    }

    vector<vector<int>> give;
    vector<vector<int>> take;

    while (!leefz.empty()) {
        unordered_set<int> newleefz;
        for (auto cur : leefz) {
            if (adj[cur].size() == 1){
                int nb = *adj[cur].begin();
                adj[cur].erase(nb);

                if (h[cur] > target) {
                    give.push_back({cur + 1, nb + 1, h[cur] - target});
                    h[nb] += h[cur] - target;
                    h[cur] = target;
                } else if (h[cur] < target) {
                    take.push_back({nb + 1, cur + 1, target - h[cur]});
                    h[nb] -= target - h[cur];
                    h[cur] = target;
                }
                h[nb] -= target-h[cur];
                adj[nb].erase(cur);
                newleefz.insert(nb);
            }
        }
        leefz = newleefz;
    }

    reverse(take.begin(), take.end());

    cout << give.size() + take.size() << '\n';

    for (auto g : give) {
        cout << g[0] << ' ' << g[1] << ' ' << g[2] << '\n';
    }

    for (int i = 0; i < take.size(); ++i) {
        cout << take[i][0] << ' ' << take[i][1] << ' ' << take[i][2] << '\n';
    }

    return 0;
}
