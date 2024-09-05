#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
	int n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> adj(n);
	for(int i=0; i<m; ++i){
		ll a,b; ll c;
		cin >> a >> b >> c;
		--a; --b;
		adj[a].push_back({c,b});
	}

	vector<ll> dist(n, LLONG_MAX);
	vector<bool> visited(n);
	dist[0] = 0;
	priority_queue<pair<ll, ll>> pq;
	pq.push({0, 0});

	while(!pq.empty()){
		pair<ll, ll> cur = pq.top();
		pq.pop();
		if(visited[cur.second]) continue;
		visited[cur.second] = true;
		for(auto x: adj[cur.second]){
			if(dist[cur.second]+x.first < dist[x.second]){
				dist[x.second] = dist[cur.second]+x.first;
				pq.push({-dist[x.second], x.second});
			}
		}
	}

	for(auto x: dist) cout << x << ' ';
}
