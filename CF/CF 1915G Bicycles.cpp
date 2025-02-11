#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
    int n, m;
    cin >> n >> m;;
    vector<vector<pair<int, int>>> adj(n);
    for(int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
        
    }
    vector<int> bikes(n);
    for(int i=0; i<n; ++i) cin >> bikes[i];

    set<vector<ll>> q;
    vector<vector<ll>> dist(n, vector<ll>(1001, 1000000000000000000));
    dist[0][bikes[0]] = 0;
    vector<int> par(n, -1);
    q.insert({0,0, bikes[0]});
    while(!q.empty()){
        auto cur = *q.begin();
        ll curdist = cur[0];
        int newcity = cur[1];
        int bike = cur[2];
        q.erase(q.begin());

        if (bikes[newcity] < bike){
            if (curdist < dist[newcity][bikes[newcity]]){
                dist[newcity][bikes[newcity]] = curdist;
                q.insert({curdist, newcity, bikes[newcity]});
            }
        }
        for(auto x: adj[newcity]){
            if(curdist + x.first*bike < dist[x.second][bike]){
                dist[x.second][bike] = curdist + x.first*bike;
                q.insert({dist[x.second][bike], x.second, bike});
            }
        }
    }
    cout << *min_element(dist[n-1].begin(), dist[n-1].end()) << '\n';
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