#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	ll c[n];
	for(int i=0; i<n; ++i) cin >> c[i];

	vector<vector<int>> adj(n);
	for (int i=0; i<m; ++i) {
		int a, b; cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int cur_comp = 1;
	int comps[n] = {0};
	map<int, ll> minprice;
	for (int i=0; i<n; ++i) {
		if (comps[i] != 0) continue;
		minprice[cur_comp] = LONG_LONG_MAX;
		stack<int> s;
		s.push(i);
		while (!s.empty()) {
			int cur = s.top();
			s.pop();
			comps[cur] = cur_comp;
			minprice[cur_comp] = min(c[cur], minprice[cur_comp]);
			for (auto x : adj[cur]) {
				if (comps[x] == 0) s.push(x);
			}
		}
		++cur_comp;
	}

	ll ans = 0;
	for (auto x : minprice) {
		ans +=  x.second;
	}
	cout << ans;
}
