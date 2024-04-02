#include <bits/stdc++.h>
#include <climits>
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
	vector<string> lmao(n);
	FL(i, 0, n) cin >> lmao[i];

	int mindif = LLONG_MAX;
	FL(i, 0, n){
		FL(j, i+1, n){
			int curdif = 0;
			FL(c, 0,m){
				curdif += abs(lmao[i][c] - lmao[j][c]);
			}
			mindif = min(curdif, mindif);
		}
	}
	cout << mindif << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
