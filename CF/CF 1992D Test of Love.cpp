#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	string s = "L";
	string p; cin >> p;
	s += p + 'L';
	n += 2;

	vi dp(n, n+1);
	vector<bool> poss(n);
	dp[n-1] = 0;
	poss[n-1] = true;
	R0F(i, n-2){
		if (s[i] == 'W'){
			if (dp[i+1] != n+1){
				poss[i] = true;
			}else{
				continue;
			}
			dp[i] = dp[i+1]+1;
		}else if (s[i] == 'L'){
			FOR(j, i+1, i+m+1){
				if (j >=n) break;
				if (s[j] == 'C' || !poss[j]) continue;
				poss[i] = true;
				dp[i] = min(dp[j], dp[i]);
			}
		}
	}
	if(poss[0] && dp[0] <=k) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
