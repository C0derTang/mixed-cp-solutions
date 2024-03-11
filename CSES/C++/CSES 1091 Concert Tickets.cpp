#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> prices;
	for (int i=0; i<n; ++i) {
		int temp;
		cin >> temp;
		++prices[temp];
	}
	while (m--) {
		int p; cin >> p;
		auto x = prices.lower_bound(p);
		if (x != prices.begin()){
			--x;
			cout << x->first << '\n';
			if (--(x->second) == 0) {
				prices.erase(x);
			}
		}else{
			cout << -1 << '\n';
		}
		
	}
}
