#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<ll> apples(n);
	ll sum = 0;
	for (int i=0; i<n; ++i) {
		cin >> apples[i];
		sum += apples[i];
	}
	
	ll ans = LLONG_MAX;

	for (int i=0; i< 1<<n; ++i){
		ll cursum = 0;

		for (int j=0; j<n; ++j){
			if (i & (1<<j)) cursum += apples[j];
		}
		ans = min(ans, abs(sum-cursum-cursum));
	}


	cout << ans;
}