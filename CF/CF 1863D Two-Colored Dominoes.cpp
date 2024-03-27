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
	vector<string> grid(n);
	FL(i, 0, n) cin >> grid[i];

	bool val = true;
	FL(i, 0, n){
		int count = 0;
		FL(j, 0, m) count += (grid[i][j] != '.');
		if (count%2 == 1){
			val = false;
			break;
		}
	}
	if (!val){
		cout << "-1\n";
		return;
	}
	FL(j, 0, m){
		int count = 0;
		FL(i, 0, n) count += (grid[i][j] != '.');
		if (count%2 == 1){
			val = false;
			break;
		}
	}
	if (!val){
		cout << "-1\n";
		return;
	}

	vi col(m);
	FL(i, 0, n){
		bool white = false;
		FL(j, 0, m){
			if(grid[i][j] == 'L'){
				grid[i][j] = (col[j] ? 'W' : 'B');
				grid[i][j + 1] = (col[j] ? 'B' : 'W');
				col[j] ^= 1;
			} else if (grid[i][j] == 'U') {
				grid[i][j] = (white ? 'W' : 'B');
				grid[i + 1][j] = (white ? 'B' : 'W');
				white ^= 1;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << grid[i] << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
