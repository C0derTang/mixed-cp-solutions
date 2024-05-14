#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

struct DSU{
	int largest = 0;

	vector<int> roots;
	vector<int> sizes;
	void init(int n) {
		roots = vector<int>(n);
		for(int i=0; i<n; ++i) roots[i] = i;
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
	bool linked(int x, int y) {return find(x) == find(y);};
};

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	DSU roads;
	roads.init(n);
	while(m--){
		int a, b;
		cin >> a >> b;
		--a; --b;
		n -= !roads.linked(a, b);
		roads.unite(a,b);
		cout << n << ' ' << roads.largest << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
