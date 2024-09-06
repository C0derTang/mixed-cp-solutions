#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))
const ll INF = 5000000000001;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(m, vector<ll>(3));
    vector<ll> dist(n, INF);
    vector<bool> affected(n);
    
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        --edges[i][0];
        --edges[i][1];
    }

    dist[0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto e : edges) {
            if (dist[e[0]] != INF) dist[e[1]] = min(dist[e[1]], dist[e[0]] - e[2]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (auto e : edges) {
            if (dist[e[0]] != INF && dist[e[0]] - e[2] < dist[e[1]]) {
                affected[e[1]] = true;
            }
        }
    }

    vector<vector<int>> adj(n);
    for (auto e : edges) {
        adj[e[0]].push_back(e[1]);
    }

    vector<bool> seen(n, false);
    for (int i = 0; i < n; ++i) {
        if (affected[i] && !seen[i]) {
            stack<int> s;
			s.push(i);
			seen[i] = true;
			
			while (!s.empty()) {
				int node = s.top();
				s.pop();
				
				for (int neighbor : adj[node]) {
					if (!seen[neighbor]) {
						seen[neighbor] = true;
						affected[neighbor] = true;
						s.push(neighbor);
					}
				}
			}
        }
    }

    cout << (affected[n-1] ? -1LL : -dist[n-1]);
}
