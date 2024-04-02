#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	string s;
	cin >> s;
	int l = 0, r=0;
	FL(i, 0, 3) l += s[i]-'0';
	FL(i, 3, 6) r += s[i]-'0';

	cout << (l==r ? "YES\n" : "NO\n");
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
