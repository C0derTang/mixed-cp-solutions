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
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n, m; cin >> n >> m;
	if(m==1){
		cout << "0\n";
		while(n--) cout << "0\n";
		return;
	}

	vector<vi> ans(n, vi(m));
	F0R(i, n) {
		iota(ans[i].begin(), ans[i].end(), 0);
		rotate(ans[i].begin(), ans[i].begin()+1, ans[i].end());//fucking problem
	}

	if(n<m){
		FOR(i, 0, n) rotate(ans[i].begin(), ans[i].begin()+(m-(m-i))+1, ans[i].end());
	}else{
		FOR(i, 1, min(m, n)) rotate(ans[i].begin(), ans[i].begin()+i-1, ans[i].end());
	}

	cout << min(n+1, m) << '\n';


	for(auto row: ans){
		for (auto x: row) cout << x << ' ';
		cout << '\n';
	}

	
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}