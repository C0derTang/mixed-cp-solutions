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
	int h; cin >> h;
	char s; cin >> s;
	string t; cin >> t;
	if (h==0) cout << "12" << s << t << " AM\n";
	else if (h < 10) cout << '0'<< h << s << t << " AM\n";
	else if (h<12) cout << h << s << t << " AM\n";
	else if (h == 12) cout << h << s << t << " PM\n";
	else if (h>12 && h-12 < 10) cout << '0' << h-12 << s << t << " PM\n";
	else cout << h-12 << s << t << " PM\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
