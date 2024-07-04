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
	int n; cin >> n;
	string s; cin >> s;
	vector<char> enc;
	vector<bool> seen(26);
	for(auto c: s){
		if (!seen[c-'a']){
			seen[c-'a'] = true;
			enc.push_back(c);
		}
	}
	sort(enc.begin(), enc.end());
	map<char, int> bash;
	F0R(i, enc.size()){
		bash[enc[i]] = enc.size()-i-1;
	}
	vector<char> ans(n);
	F0R(i, n){
		ans[i] = enc[bash[s[i]]];
	}
	for(auto x: ans) cout << x;
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
