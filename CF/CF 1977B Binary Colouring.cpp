#include <bits/stdc++.h>

using namespace std;

#define ll long long

// break bit problems down, you can usually take one and look at it greedily

void solve(){
	ll x; cin >> x;
	
	vector<int> res(31);
	for(int i=0; i<30;++i){
		if (1ll & (x>>i)){
			if (res[i]){
				res[i+1] = 1;
				res[i] = 0;
			} else if (i > 0){
				if (res[i-1] == 1){
					res[i+1] = 1;
					res[i-1] = -1;
				}else{
					res[i] = 1;
				}
			}else if(i == 0){
				res[i] = 1;
			}
		}
	}

	cout << 31 << '\n';
	for(auto n: res) cout << n << ' ';
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
