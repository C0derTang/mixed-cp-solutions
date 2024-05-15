#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int> roots;
	vector<int> sizes;
	int largest = 1;
	void init(int n) {
		roots = vector<int>(n);
		for(int i=0; i<n; ++i) {
			roots[i] = i;
		}
		sizes = vector<int>(n, 1);
	}
	int find(int x) {return roots[x] == x ? x: (roots[x] = find(roots[x]));}
	bool unite(int x, int y){
		int rx = find(x);
		int ry = find(y);
		if (rx == ry) return false;
		if (sizes[rx] < sizes[ry]) swap(rx, ry);
		sizes[rx] += sizes[ry];
		largest = max(largest, sizes[rx]);
		roots[ry] = rx;
		return true;
	}
	bool linked(int x, int y) {return find(x) == find(y);}
};

int main() {
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	DSU farm;
	farm.init(n);
	
	vector<vector<int>> adj(n);
	while(m--){
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> order(n);
	for (int i=0; i<n; ++i) cin >> order[i];
	reverse(order.begin(), order.end());

	set<int> visited;
	vector<string> ans(n);
	for (int i=0; i<n; ++i){
		--order[i];
		visited.insert(order[i]);
		for(auto x: adj[order[i]]){
			if (visited.find(x) != visited.end()) farm.unite(order[i], x);
		}
		ans[i] = (farm.largest >= i+1 ? "YES\n" : "NO\n");
	}
	for(int i=n-1; i> -1; --i) cout << ans[i];
}
