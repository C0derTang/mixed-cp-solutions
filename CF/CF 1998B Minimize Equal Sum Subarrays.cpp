#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

struct DSU{
	vi roots;
	vi sizes;
	void init(int n) {
		roots = vi(n);
		for(int i=0; i<n; ++i) roots[i] = i;
		sizes = vi(n, 1);
	}
	int find(int x) {return roots[x] == x ? x: (roots[x] = find(roots[x]));}
	bool unite(int x, int y){
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

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n; cin >> n;
	vi p(n);
	F0R(i, n) cin >> p[i];
	rotate(p.begin(), p.begin()+1, p.end());
	for(auto x: p) cout << x << ' ';
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
