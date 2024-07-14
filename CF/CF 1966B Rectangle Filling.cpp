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
	int n, m; cin >> n >> m;

	bool uw=false, ub=false, lw=false, lb=false, rw=false, rb=false, dw=false, db=false;
	F0R(i, n){
		string s; cin >> s;
		if (i==0){
			if (s.find("W") != string::npos) uw=true;
			if (s.find("B") != string::npos) ub=true;
		}
		if (i==n-1){
			if (s.find("W") != string::npos) dw=true;
			if (s.find("B") != string::npos) db=true;
		}
		if (s[0] == 'W') lw=true;
		else lb=true;

		if (s[m-1] == 'W')rw=true;
		else rb=true;
	}
	
	cout << (((uw&&lw&&rw&&dw) || (ub&&lb&&rb&&db)) ? "YES\n" : "NO\n");

}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
