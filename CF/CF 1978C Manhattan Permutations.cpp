#include <bits/stdc++.h>

using namespace std;

#define int long long

// i am bad at observings

void solve(){
	int n, k;
	cin >> n >> k;

	int stupid = 0;
	for(int i=1; i<=n; ++i) stupid += abs(i-(n-(i-1)));

	if (k%2 == 1 || k > stupid){
		cout << "No\n";
		return;
	}
	cout << "Yes\n";

	
	
	if (k == 0) {for(int i=1; i<=n; ++i) cout << i << ' ';}
	else if (k == stupid) {for(int i=n; i>0; --i) cout << i << ' ';}
	else{
		vector<int> ans(n);
		for(int i=0; i<n; ++i) ans[i] = i+1;
		
		k /= 2;
		for(int i=0; k>0; ++i){
			if (k >= n-1 - 2*i){
				swap(ans[i], ans[n-1-i]);
				k -= n-1 - 2*i;
			}else{
				swap(ans[i], ans[i+k]);
				k = 0;
			}
		}

		for(auto x: ans) cout << x << ' ';
	}
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
