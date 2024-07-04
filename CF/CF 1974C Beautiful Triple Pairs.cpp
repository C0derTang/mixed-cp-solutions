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
	vi a(n);
	F0R(i, n) cin >> a[i];

	ll ans = 0;
	set<vector<int>> seen;
	map<pii, int> fs;
	map<pii, map<int, int>> fssep;

	map<pii, int> st;
	map<pii, map<int, int>> stsep;

	map<pii, int> ft;
	map<pii, map<int, int>> ftsep;

	FOR(i, 2, n){
		int f = a[i-2];
		int s = a[i-1];
		int t = a[i];

		ans += fs[{f, s}];
		ans -= fssep[{f, s}][t];
		++fs[{f, s}];
		++fssep[{f, s}][t];

		ans += st[{s, t}];
		ans -= stsep[{s, t}][f];
		++st[{s, t}];
		++stsep[{s, t}][f];

		ans += ft[{f, t}];
		ans -= ftsep[{f, t}][s];
		++ft[{f, t}];
		++ftsep[{f,t}][s];
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int tt; cin >> tt; // = 1;
	while(tt--){
		solve();
	}
}
