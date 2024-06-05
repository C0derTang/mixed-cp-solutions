#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	int n, m;
	cin >> n >> m;
	map<char,  int> lmao;

	string temp = "ABCDEFG";
	for(auto x: temp) lmao[x] = 0;
	
	string s;
	cin >> s;
	for(auto x: s) ++lmao[x];
	
	int ans = 0;
	for (auto x: lmao){
		ans += max(0, m-x.second);
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}