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
	string s; cin >> s;

	int rx=0, ry=0, hx=0, hy=0;

	vector<char> ans(n);
	bool hm=false, rm=false;

	F0R(i,n){
		if (s[i] == 'N'){
			if (ry > hy){++hy; ans[i]='H'; hm=true;}
			else if (ry < hy){++ry; ans[i]='R'; rm=true;}
			else{
				if (!rm) {++ry; ans[i]='R'; rm=true;}
				else {++hy; ans[i]='H'; hm=true;}
			}
		}else if (s[i] == 'E'){
			if (rx > hx){++hx; ans[i]='H'; hm=true;}
			else if (rx<hx){++rx; ans[i]='R'; rm=true;}
			else{
				if (!rm) {++rx; ans[i]='R'; rm=true;}
				else {++hx; ans[i]='H'; hm=true;}
			}
		}else if (s[i] == 'S'){
			if (ry > hy){--ry; ans[i]='R'; rm=true;}
			else if (ry < hy){--hy; ans[i]='H'; hm=true;}
			else{
				if (!rm) {--ry; ans[i]='R'; rm=true;}
				else {--hy; ans[i]='H'; hm=true;}
			}
		}else{
			if (rx > hx){--rx; ans[i]='R'; rm=true;}
			else if (rx < hx){--hx; ans[i]='H'; hm=true;}
			else{
				if (!rm) {--rx; ans[i]='R'; rm=true;}
				else {--hx; ans[i]='H'; hm=true;}
			}
		}
	}
	if (hm && rm && rx==hx && ry==hy){
		for(auto x: ans) cout << x;
	}else{
		cout << "NO";
	}
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
