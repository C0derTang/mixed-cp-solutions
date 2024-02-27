#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, r;
	cin >> n >> m >> r;

	int cows[n];
	pair<int, int> store[m];
	int rent[r];

	for (int i=0; i<n; ++i) {
		cin >> cows[i];
	}
	for (int i=0; i<m; ++i) {
		cin >> store[i].second >> store[i].first;
	}
	for (int i=0; i<r; ++i) {
		cin >> rent[i];
	}

	sort(cows, cows+n, greater<int>());
	sort(store, store+m, greater<pair<int, int>>());
	sort(rent, rent+r, greater<int>());

	long long ans = 0;
	int rind = 0;
	int sind = 0;
	int cind = 0;
	while (cind < n){
		int sellcost = 0;
		int tsind = sind;
		int tcow = cows[cind];
		int rem = 0;
		while (tsind < m){
			int sold = min(store[tsind].second, tcow);
			sellcost += sold*store[tsind].first;
			tcow -= sold;
			if (tcow == 0){
				rem = sold;
				break;
			}else{
				++tsind;
			}
		}
		

		if (rind < r && rent[rind] > sellcost){
			ans += rent[rind];

			++rind;
			--n;
		}else{
			ans += sellcost;
			sind = tsind;
			if (sind < m){
				store[sind].second -= rem;
			}
			++cind;
		}
		
	}
	cout << ans;
}
