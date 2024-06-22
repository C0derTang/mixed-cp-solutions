#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> h(n);
	for(int i=0; i<n; ++i) cin >> h[i];

	vector<int> cost(n, INT32_MAX);
	cost[0] = 0;
	for(int i=0; i<n-1; ++i){
		cost[i+1] = min(cost[i+1], cost[i]+abs(h[i+1] - h[i]));
		if (i+2 < n) cost[i+2] = min(cost[i+2], cost[i]+abs(h[i+2] - h[i]));
	}

	cout << cost[n-1];
}
