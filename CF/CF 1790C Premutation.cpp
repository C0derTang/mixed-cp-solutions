#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
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
	int n; cin >> n;
	vector<set<int>> adj(n+1);
	F0R(meh, n){
		vi a(n-1);
		F0R(i, n-1) cin >> a[i];
		
		F0R(i, n-2){
			adj[a[i]].insert(a[i+1]);
		}
	}

	vi ans(n);
	vector<bool> seen(n+1);
	F0R(i, n){
		FOR(j, 1, n+1){
			if (adj[j].empty() && !seen[j]){
				ans[n-i-1] = j;
				seen[j] = true;
				break;
			}
		}
		FOR(j, 1, n+1) adj[j].erase(ans[n-i-1]);
	}
	
	for(auto x: ans) cout << x << ' ';
	cout << '\n';
	
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
