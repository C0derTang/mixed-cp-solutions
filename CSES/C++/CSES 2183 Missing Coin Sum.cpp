#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<ll> coins (n);
	for(int i=0; i<n; ++i) cin >> coins[i];

	sort(coins.begin(), coins.end());
	
	// 1 1 3 5 6
	// asking to find mex of all possible combos of coins in the array.
	// prefix sum would not work bc im a stupid idiot
	// not sliding windows either

	//WAIT BRO WTF ITS LITERALLY IF A[I+1] == CUM_SUM + 1

	ll cum_sum = 0;
	for (auto x: coins){
		if (x > cum_sum+1){
			cout << cum_sum+1;
			return;
		}
		cum_sum += x;
	}
	cout << cum_sum+1;

}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
