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

    bool linked(int x, int y) {return find(x) == find(y);}
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU fdsu, gdsu;
    fdsu.init(n);
    gdsu.init(n);

    vector<pair<int, int>> edges(m1);
    for(int i=0; i<m1; ++i) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first; --edges[i].second;
    }

    for(int i=0; i<m2; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        gdsu.unite(u,v);
    }

    ll ans = 0;
    for(auto x: edges){
        if (!gdsu.linked(x.first, x.second)) ++ans;
        else fdsu.unite(x.first, x.second);
    }

    map<int, set<int>> comp;
    for(int i=0; i<n; ++i){
        comp[gdsu.find(i)].insert(fdsu.find(i));
    }

    for(auto x: comp){
        if (x.second.size() > 1){
            ans += x.second.size()-1;
        }
    }

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
