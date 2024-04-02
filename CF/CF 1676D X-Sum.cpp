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
	int n, m;
	cin >> n >> m;

	vector<vi> board(n, vi(m));
	FL(i, 0, n) FL(j, 0, m) cin >> board[i][j];

	map<int, int> ldiag, rdiag;
	FL(i, 0, n){
		FL(j, 0, m){
			ldiag[i+j] += board[i][j];
			rdiag[i-j] += board[i][j];
		}
	}


	int ans=0;
	FL(i, 0, n){
		FL(j, 0, m){
			ans = max(ans, ldiag[i+j] + rdiag[i-j] - board[i][j]);
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
