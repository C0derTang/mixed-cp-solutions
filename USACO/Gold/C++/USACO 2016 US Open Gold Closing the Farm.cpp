#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

struct DSU {
    vector<int> roots;
    vector<int> sizes;
    int largest = 1;
 
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
        largest = max(largest, sizes[rx]);
        return true;
    }

    bool linked(int x, int y) {return find(x) == find(y);}

};


signed main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n, m;
	cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> q(n);
    for(int i=n-1; i>-1; --i){
        cin >> q[i];
        --q[i];
    }

    DSU bash;
    bash.init(n);
    
    vector<string> ans(n);
    vector<bool> open(n);
    for(int i=0; i<n; ++i){
        open[q[i]] = true;
        for(auto x: adj[q[i]]){
            if (open[x]) bash.unite(q[i], x);
        }
        ans[i] = (bash.largest == i+1) ? "YES\n":"NO\n";
    }
	for(int i=n-1; i>-1; --i) cout << ans[i];
}
