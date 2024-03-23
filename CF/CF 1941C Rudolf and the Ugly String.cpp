#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;

	int ans = 0;
	int i=0;
	while (i<n-2) {
		if ((s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p') || (s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e')){
			++ans;
			i += 3;
		}else{
			++i;
		}
	}

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}