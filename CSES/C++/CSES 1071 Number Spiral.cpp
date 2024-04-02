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
	int y, x;
	cin >> y >> x;
	if (max(y,x) % 2 == 0) cout << (y == max(y,x) ? max(y,x) * max(y,x) - (x-1) : (max(y,x)-1) * (max(y,x)-1)+1 + (y-1));
	else cout << (y == max(y,x) ? (max(y,x)-1) * (max(y,x)-1)+1 + (x-1) : (max(y,x)) * (max(y,x)) - (y-1));
	cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}