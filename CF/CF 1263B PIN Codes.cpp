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
	int n; cin >> n;

	vector<bool> canuse(10, true);
	vector<vector<char>> lmao(n, vector<char>(4));
	for(int i=0; i<n; ++i){
		for(int j=0; j<4; ++j) cin >> lmao[i][j];
		canuse[lmao[i][3]-'0'] = false;
	}

	set<vector<char>> seen;
	int changes = 0;
	for(int i=0; i<n; ++i){
		if (seen.count(lmao[i])){
			++changes;

			int replace = 0;
			for(int j=0; j<10; ++j){
				if (canuse[j]){
					replace = j;
					canuse[j] = false;
					break;
				}
			}
			lmao[i][3] = replace + '0';
		}
		seen.insert(lmao[i]);
	}
	cout << changes << '\n';
	for(auto s: lmao){
		for (auto c: s) cout << c;
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
