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
	vector<string> a(2);
	cin >> a[0] >> a[1];

	string ans = "";
	pii cur={0,0};
	while(cur != make_pair(1,n-1)){
		ans += a[cur.first][cur.second];
		char r = (cur.second+1<n ? a[cur.first][cur.second+1] : '2');
		char d = (cur.first+1 >1 ? '2' : a[cur.first+1][cur.second]);

		if (d < r){
			++cur.first;
		}else{
			++cur.second;
		}
	}
	ans+=a[1][n-1];

	int ind=0;
	F0R(i, n){
		if (a[0][i]==ans[i])++ind;
		else break;
	}

	int dp=1;
	ROF(i, 1, ind-1){
		if (a[1][i-1] == a[0][i]) ++dp;
		else break;
	}
	
	cout << ans << '\n' << dp << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}