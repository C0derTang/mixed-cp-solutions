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

void solve(){
	int n; cin >> n;
	vi a(n);
	int ans=0;
	F0R(i, n) cin >> a[i];
	F0R(cheese, 2){
		vi count(n+1);
		set<int> dup;
		dup.insert(0);
		F0R(i,n){
			ans += a[i];
			++count[a[i]];
			if (count[a[i]] > 1) dup.insert(a[i]);
			a[i] = *dup.rbegin();
		}
	}

	vi bcount(n+1);
	vi last(n+1, 0);
	F0R(i, n){
		++bcount[a[i]];
		last[a[i]] = i;
	}

	F0R(i, n+1){
		ans += (i*bcount[i]*(bcount[i]+1))/2;
		if (bcount[i] > 1){
			ans += (i*bcount[i])* max(n-last[i]-1, 0LL);
		}
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