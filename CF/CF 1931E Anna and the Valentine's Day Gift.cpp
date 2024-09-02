#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<pair<T, long long>, null_type, less<pair<T, long long>>, rb_tree_tag, tree_order_statistics_node_update>;

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


void solve() {
    int n, m;
	cin >> n >> m;
	vi lmao(n);
	int ans=0;
	F0R(i, n){
		string x;
		cin >> x;
		int dum=0;
		R0F(j, x.size()-1){
			if (x[j] =='0')++dum;
			else break;
		}
		lmao[i] = dum;
		ans += x.size();
	}
	sort(lmao.begin(), lmao.end());
	R0F(i, n-1){
		if (i%2==(n-1)%2) ans -= lmao[i];
		if (lmao[i]==0)break;
	}
	cout << (ans > m ? "Sasha\n" : "Anna\n");
	
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
