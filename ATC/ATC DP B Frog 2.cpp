#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for(int i=0; i<n; ++i) cin >> h[i];

	vector<int> cost(n, INT32_MAX);
	cost[0] = 0;
	for(int i=0; i<n-1; ++i){
		for(int j=1; j<=k; ++j){
			if (i+j < n) cost[i+j] = min(cost[i+j], cost[i]+abs(h[i+j] - h[i]));
		}
	}

	cout << cost[n-1];
}
