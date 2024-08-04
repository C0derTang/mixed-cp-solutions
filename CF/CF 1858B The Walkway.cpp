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
	int n, m, d;
	cin >> n >> m >> d;
	vi s;
	bool lame=false;
	F0R(i, m){
		int x; cin >> x;
		if (i==0LL && x != 1){
			s.push_back(1);
			lame=true;
		}
		s.push_back(x);
	}
	m += lame;

	int ans=1;
	F0R(i, m-1) ans += (s[i+1]-s[i])/d + ((s[i+1]-s[i])%d != 0);
	ans += (n-s[m-1])/d;

	int min = 0, count = 0;
	FOR(i, 1, m-1){
		int org = (s[i+1]-s[i-1])/d + ((s[i+1]-s[i-1])%d != 0);
		int p1 = (s[i]-s[i-1])/d + ((s[i]-s[i-1])%d != 0);
		int p2 = (s[i+1]-s[i])/d + ((s[i+1]-s[i])%d != 0);
		count += org < (p1+p2);
	}

	if ((n-s[m-2])/d < (s[m-1]-s[m-2])/d + ((s[m-1]-s[m-2])%d != 0) + (n-s[m-1])/d) ++count;

	if (count > 0){
		cout << ans-1 << ' ' << count << '\n';
	}else{
		cout << ans << ' ' << m-1+(!lame) << '\n';
	}
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
