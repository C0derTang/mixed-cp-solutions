#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> leafs;
    for(int i=0; i<n; ++i) if (adj[i].size() == 1) leafs.push(i);
    
    vector<int> dist(n, -1);
    int level = 0;
    while(!leafs.empty()){
        int temp = leafs.size();
        while(temp--){
            int cur = leafs.front();
            leafs.pop();
            dist[cur] = level;
            for(auto x: adj[cur]) if (dist[x] == -1) leafs.push(x);
        }
        ++level;
    }
    for(auto x: dist) cout << x << ' ';
    cout << '\n';

    ll ans = 0;
    for(auto x: dist) ans += (x==0);
    ans *= n-ans;
    int g1 = 0;
    for(auto x: dist) g1 += (x>1);
    int g2=0;
    // requirements: if the node's shortest path is 2
    // and it has a neighbor with a shortest path of 1
    // and that neighbor has at least 3 neighbors
    for(int i=0; i<n; ++i){
        if (dist[i] != 2) continue;
        for(auto x: adj[i]){
            if (dist[x] == 1 && adj[x].size() > 2){
                ++g2;
                continue;
            }
        }
    }
    ans += g1*g2;
    cout << ans << '\n';
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}