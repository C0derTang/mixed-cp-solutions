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
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	--a; --b; --c; --d;

	int intersec = 0;
	while (a != b){
		++a; a%=12;
		if (a==c || a==d) ++intersec;
	}

	cout << (intersec%2 ? "YES\n" : "NO\n");
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
