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
	int a,b,c;
	cin >> a >> b >> c;
	
	int children = 0;
	if (a>0){
		--a;
		children = 2;
	}else if (b>0){
		--b;
		children = 1;
	}else{
		if (c>1) cout <<"-1\n";
		else cout << "0\n";
		return;
	}

	int ans = 0;
	while(children > 0 && a+b+c > 0){
		int newchildren = 0;

		int da = min(children, a);
		newchildren += da*2;
		children -= da;
		a -= da;

		int db = min(children, b);
		newchildren += db;
		children -= db;
		b -= db;

		int dc = min(children, c);
		children -= dc;
		c -= dc;

		children = max(children, newchildren);
		++ans;
	}

	if (children +a+b+c > 0) cout << "-1\n";
	else cout << ans << '\n';

}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
