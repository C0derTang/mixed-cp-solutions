#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return (a.first + b.first < a.second + b.second);
}

void solve(){
	int n; cin >> n;
	vector<int> a(n), b(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<n; ++i) cin >> b[i];

	int m1=0, m2=0, pos=0, neg=0;
	for(int i=0; i<n; ++i){
		if (a[i] == b[i]){
			pos += a[i]==1;
			neg += a[i]==-1;
		}else{
			if (a[i] > b[i]){
				m1 += a[i];
			}else{
				m2 += b[i];
			}
		}
	}

	int ans = -200000;
	for(int i=-neg; i<=pos; ++i){
		ans = max(ans, min(m1+i, m2+(pos-neg-i)));
	}
	cout << ans << '\n';
	
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
