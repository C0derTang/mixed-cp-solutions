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

    map<int, set<int>> bash;
    for(int i=0; i<n; ++i) bash[adj[i].size()].insert(i);

    int maxans = 0;
    for(int i=0; i<n; ++i){
        int curans=adj[i].size();
        bash[adj[i].size()].erase(i);
        if (bash[adj[i].size()].empty()) bash.erase(adj[i].size());
        for(auto x: adj[i]){
            bash[adj[x].size()-1].insert(x);
            bash[adj[x].size()].erase(x);
            if (bash[adj[x].size()].empty()) bash.erase(adj[x].size());
        }
        maxans = max(curans + bash.rbegin()->first-1, maxans);
        for(auto x: adj[i]){
            bash[adj[x].size()-1].erase(x);
            bash[adj[x].size()].insert(x);
            if (bash[adj[x].size()-1].empty()) bash.erase(adj[x].size()-1);
        }
        bash[adj[i].size()].insert(i);

    }
    cout << maxans << '\n';
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