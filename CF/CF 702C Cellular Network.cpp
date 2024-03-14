#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	unordered_set<int> cities;
	for (int i=0; i<n; ++i) {
		int city; cin >> city;
		cities.insert(city);
	}
	set<int> cells;
	for (int i=0; i<m; ++i) {
		int cell; cin >> cell;
		cells.insert(cell);
	}

	int ans = 0;
	for (auto city : cities) {
		auto it = cells.lower_bound(city);
		int dist;
		if (it == cells.end()) {
			dist = city - *cells.rbegin();
		}
		else{
			dist = *it - city;
			if (it != cells.begin()){
				--it;
				dist = min(dist,city - *it);
			}
		}
		
		ans = max(ans, dist);
	}
	cout << ans;
}
