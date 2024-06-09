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
	vector<int> a(n);
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}

	bool allsame = true;
	for(int i=0; i<n-1; ++i){
		if(a[i] != a[i+1]){
			allsame = false;
			break;
		}
	}

	int l = 1;
	if (a[l] == a[n-1]) {
		++l;
	}

	if (allsame){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i=0; i<l; ++i) cout << 'B';
	for(int i=l; i<n; ++i) cout << 'R';
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
