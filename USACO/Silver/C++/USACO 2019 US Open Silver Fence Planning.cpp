#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


signed main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cows(n);
    for(int i=0; i<n; ++i) cin >> cows[i].first >> cows[i].second;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = 4000000000;
    vector<bool> visited(n);
    for(int i=0; i<n; ++i){
        if (visited[i]) continue;
        stack<int> st;
        st.push(i);
        int minx = cows[i].first;
        int maxx = cows[i].first;
        int miny = cows[i].second;
        int maxy = cows[i].second;
        while(!st.empty()){
            int cur = st.top();
            st.pop();
            visited[cur] = true;
            minx = min(minx, cows[cur].first);
            maxx = max(maxx, cows[cur].first);
            miny = min(miny, cows[cur].second);
            maxy = max(maxy, cows[cur].second);
            for(auto x: adj[cur]) if (!visited[x]) st.push(x);
        }
        ans = min(ans, 2LL*(maxy-miny)+2LL*(maxx-minx));
    }
    cout << ans;
}
