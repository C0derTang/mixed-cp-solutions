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
    return a.second == 1 && b.second != 1;
}

//ugly asf i wanna kms
void solve(){
	int n, k;
	cin >> n >> k;

	set<int> a1, a2;
	F0R(i, n){
		int x; cin >> x;
		if (a1.count(x)){
			a1.erase(x);
			a2.insert(x);
		}else{
			a1.insert(x);
		}
	}

	set<int> b1, b2;
	F0R(i, n){
		int x; cin >> x;
		if (b1.count(x)){
			b1.erase(x);
			b2.insert(x);
		}else{
			b1.insert(x);
		}
	}

	int len=2*k;
	vi a, b;
	while(len>0){
		if (len==1 || a2.empty()){
			a.push_back(*a1.begin());
			a1.erase(a1.begin());
			b.push_back(*b1.begin());
			b1.erase(b1.begin());
			--len;
		}else{
			a.push_back(*a2.begin());
			a.push_back(*a2.begin());
			a2.erase(a2.begin());
			b.push_back(*b2.begin());
			b.push_back(*b2.begin());
			b2.erase(b2.begin());
			len -=2;
		}
	}
	for(auto x: a) cout << x << ' ';
	cout << '\n';
	for(auto x: b) cout << x << ' ';
	cout << '\n';
	
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
