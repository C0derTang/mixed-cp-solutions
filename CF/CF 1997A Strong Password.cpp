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

const string ab = "abcdefghijklmnopqrstuvwxyz";

void solve(){
	string s;
	cin >> s;
	bool newc=false;
	F0R(i, s.size()-1){
		cout << s[i];
		if (!newc && s[i] == s[i+1]){
			newc=true;
			cout << ab[(s[i]-'a'+1)%26];
		}
	}
	cout << s[s.size()-1];
	if (!newc) cout << ab[(s[s.size()-1]-'a'+1)%26];;
	cout << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
