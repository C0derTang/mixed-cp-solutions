#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<pair<T, long long>, null_type, less<pair<T, long long>>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pii a, pii b) {
    return a.second < b.second;
}


signed main() {
    
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    int n; cin >> n;
    vector<vi> adj(n);
    F0R(i, n-1){
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=0;
    for(auto x: adj) ans = max(ans, (int)x.size());
    cout << ans;

/* dumb brute force
    vi colors(n, -1);
    vector<bool> seen(n);
    seen[0] = true;
    colors[0]=0;
    queue<pii> q;
    q.push({0,-1});
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        int c=0;
        for(auto x: adj[cur.first]){
            if(seen[x]) continue;
            seen[x] = true;
            while (c==colors[cur.first] || c==cur.second) ++c;
            colors[x]=c;
            q.push({x,colors[cur.first]});
            ++c;
        }
        
    }
    cout << *max_element(colors.begin(), colors.end())+1;
    */
}
