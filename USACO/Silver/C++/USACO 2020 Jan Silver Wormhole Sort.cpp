#include <bits/stdc++.h>
using namespace std;

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

struct DSU{
	vector<int> roots;
	vector<int> sizes;
	int largest = 1;
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
	bool linked(int x, int y) {return find(x) == find(y);}
};

int main() {
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
	

	//requirements:
	// every item has to be sorted
	// it should matter the order
	// 3 2 1 4
	// 1 2 9
	// 1 3 7
	// 2 3 10
	// 2 4 3

	// 3 2 1 4
	// 1 2 9
	// 1 3 100
	// 2 3 10
	// 2 4 3

	// shitty approach #1 (too expensive)
	// 1 check what cows are already sorted, keep track of which postions are unsorted
	// 2 sort wormholes by largest size
	// 3 go through wormholes largest to smallest
	// 4 for each wormhole, update the dsu
	// 5 check if the two cows at the end of the wormholes are connected to the cows at the position they should be in
	//if it is remove from set of unsorted values
	// break unsorted is emptyonce all unsorted postions are connected to their intended positions
	// mnlog(n) + mlogm slow af bitch

	//shitty approach #2
	// bsearch or wormhole width
	// create new dsu every time and check all connectivities

	
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	unordered_map<int, int> unsorted;
	for(int i=0; i<n; ++i){
		cin >> p[i];
		--p[i];
		if (i != p[i]){
			unsorted[i] = p[i];
		}
	}
	
	if (unsorted.empty()){
		cout << "-1";
		return 0;
	}

	vector<vector<int>> wormholes(m, vector<int>(3));
	for(int i=0; i<m; ++i){
		cin >> wormholes[i][1] >> wormholes[i][2] >> wormholes[i][0];
		--wormholes[i][1]; --wormholes[i][2];
	}
	sort(wormholes.begin(), wormholes.end(), greater<>());

	DSU paths;
	paths.init(n);
	int ans = 1000000001;
	for (auto wormhole: wormholes){
		ans = min(ans, wormhole[0]);
		paths.unite(wormhole[1], wormhole[2]);
		bool val = true;
		for (auto x: unsorted){
			if (!paths.linked(x.first, x.second)){
				val = false;
				break;
			}
		}
		if (val) break;
	}
	cout << ans;
}