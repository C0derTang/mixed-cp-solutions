#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n;
	cin >> n;
	vi p(n);
	for (int i=0; i<n; ++i) {
		cin >> p[i];
	}
	
	vector<vi> vals(n, vi(n+1));

	for (int i=0; i<n; ++i) {
		for (int j=n-1; j>i; --j) {
			if (p[j] < p[i]) {
				vals[i][j]=vals[i][j+1]+1;
			}else{
				vals[i][j] = vals[i][j+1];
			}
		}
	}

	for (int i=1; i<n; ++i) {
		for (int j=i+1; j<n+1; ++j) {
			vals[i][j] += vals[i-1][j];
		}
	}

	int ans=0;
	for (int i=0; i<n-3; ++i) {
		for (int j=i+2; j<n-1; ++j) {
			if (p[j] > p[i]) {
				ans += vals[j-1][j+1] - vals[i][j+1];
			}
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
