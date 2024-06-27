#include <bits/stdc++.h>

using namespace std;

#define int long long


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
    
    map<int, int> newadj;
    map<int, vector<int>> dist;
    queue<pair<int, int>> kyu;
    kyu.push({0, -1});
    int layer = 0;
    while (!kyu.empty()){
        int len = kyu.size();
        while (len--) {
            int node = kyu.front().first;
            int parent = kyu.front().second;
            kyu.pop();
            newadj[node] = parent;
            dist[layer].push_back(node);
            for(auto x: adj[node]){
                if (x != parent){
                    kyu.push({x, node});
                }
            }
        }
        ++layer;
    }

    vector<int> children(n);

    for(int i=1; i<n; ++i){
        if (adj[i].size() == 1) children[i] = 1;
    }

    for(int i=layer-1; i > 0; --i){
        for(auto x: dist[i]){
            children[newadj[x]] += children[x];
        }
    }

    int q; cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        --x; --y;
        cout << children[x] * children[y] << '\n';
    }
}


signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
