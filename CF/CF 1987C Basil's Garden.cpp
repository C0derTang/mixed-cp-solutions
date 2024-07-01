#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve(){
    int n; cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; ++i) cin >> h[i];
    h.push_back(0);

    vector<int> dp(n+1);
    for(int i=n-1; i>-1; --i){
        if (h[i] >h[i+1]){
            dp[i] = max(h[i], dp[i+1] + 1); //fix this
        }else if(h[i] < h[i+1]){
            dp[i]  = dp[i+1] +max((int)0, h[i+1]-dp[i+1]-h[i])+1;
        }else{
            dp[i] = dp[i+1]+1;
        }
    }
    cout << dp[0] << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
