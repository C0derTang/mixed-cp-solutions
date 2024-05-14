#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

class DSU{
	private:
		vector<int> roots;
		vector<int> sizes;
	public:
		DSU(int size): roots(size), sizes(size, 1){
			for (int i=0; i<size; ++i) roots[i]=i;
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

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;

	DSU graph(n);
	while (q--){
		int t, u, v;
		cin >> t >> u >> v;
		if (t==0) graph.unite(u, v);
		else{
			cout << graph.linked(u, v) << '\n';
		}
	}
}
