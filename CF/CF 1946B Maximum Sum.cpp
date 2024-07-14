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

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

// kadane orz?
void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	F0R(i, n) cin >> a[i];
	int maxsum=0, cursum=0, totsum =0;
	for(auto x: a){
		totsum += x;
		cursum = max(cursum+x, (int)0);
		maxsum = max(cursum, maxsum);
	}
	while(k--){
		totsum += maxsum;
		maxsum *=2;
		maxsum = MOD(maxsum, (int)1000000007);
		totsum = MOD(totsum , (int)1000000007);
	}

	cout << totsum << '\n';

}
//kadane orz

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
