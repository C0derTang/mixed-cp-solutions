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
	int n; cin >> n;
	vi b(n-1);
	F0R(i, n-1) cin >> b[i];

	if(n==2){
		cout << b[0] << ' ' <<b[0] << '\n';
		return;
	}

	vi a(n);
	a[0] = b[0];
	FOR(i, 1, n-1){
		a[i] = b[i]|b[i-1];
	}

	a[n-1] = b[n-2];

	F0R(i, n-1){
		if ((a[i] & a[i+1]) != b[i]){
			cout << "-1\n";
			return;
		}
	}

	for(auto x: a) cout << x << ' ';
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
