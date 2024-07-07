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



const int MAXVAL = 1000000050000;

void solve(){
	int n, k; 
	cin >> n >> k;
	vi a(n);
	F0R(i, n) cin >> a[i];
	int l=1, r=MAXVAL;
	while(l<r){
		int mid = (l+r)/2;
		int tempk = k;
		for(auto x: a) tempk -= max((int)0, mid-x);
		if (tempk >= 0) l=mid+1;
		else r=mid;
	}

	int fuck=k;
	F0R(i, n){
		if (fuck == 0) break;
		if (a[i] < l-1){
			if (l-1 - a[i] > fuck){
				a[i] += fuck;
				fuck =0;
			}else{
				fuck -= l-1 - a[i];
				a[i] = l-1;
			}
		}
	}



	int ans = (l-2)*n + 1;
	for(auto x: a) if (x >=l) ++ans;
	cout << ans+fuck << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
