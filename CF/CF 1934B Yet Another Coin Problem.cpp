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
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

vi coins = {1, 3, 6, 10, 15};
vi precomp(30, 10000000000);

void solve(){
	precomp[0] = 0;
	FOR(i, 1, 30){
		for(auto x: coins){
			if (i-x < 0) break;
			precomp[i] = min(precomp[i], precomp[i-x]+1);
		}
	}
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	solve();
	int t; cin >> t; // = 1;
	while(t--){
		int n; cin >> n;
		cout << (n > 29? precomp[n%15+15] + n/15 -1 : precomp[n])<< '\n';
	}
}
