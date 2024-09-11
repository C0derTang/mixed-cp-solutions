#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const ll INF = 200000000000001;

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
   
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, int>>> adj(n);

    for(int i=0; i<m; ++i){
        int a,b; ll c;
        cin >> a >> b >> c;
        --a; --b;
        adj[a].push_back({c, b});
    }

    vector<ll> dist(n, INF);
    vector<ll> mdist(n, INF);
    dist[0] = 0;
    mdist[0] = 0;
    priority_queue<pair<ll, pair<int, bool>>, vector<pair<ll, pair<int, bool>>>, greater<pair<ll, pair<int, bool>>>> pq;
    pq.push({0,{0,false}});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ll cur_dist = cur.first;
        int node = cur.second.first;
        bool discount = cur.second.second;

        if (discount && cur_dist > mdist[node]) continue;
        if (!discount && cur_dist > dist[node]) continue;

        for(auto x: adj[node]){
            ll weight = x.first;
            int neighbor = x.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], {neighbor, false}});
            }

            if (!discount && dist[node] + weight / 2 < mdist[neighbor]) {
                mdist[neighbor] = dist[node] + weight / 2;
                pq.push({mdist[neighbor], {neighbor, true}});
            }

            if (mdist[node] + weight < mdist[neighbor]) {
                mdist[neighbor] = mdist[node] + weight;
                pq.push({mdist[neighbor], {neighbor, true}});
            }
        }
    }
    cout << min(mdist[n-1], dist[n-1]);
}
