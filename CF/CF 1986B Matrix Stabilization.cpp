#include <bits/stdc++.h>

using namespace std;

#define ll long long


bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};


void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> grid[i][j];

	for(int lmao = 0; lmao < 1; ++lmao){ // lazy
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				bool big = true;
				int firstval = 0;
				for(int d=0; d<4; ++d){
					int ti = i+dx[d];
					int tj = j+dy[d];
					if (ti<0 || ti>=n || tj<0 || tj>=m) continue;
					if (grid[ti][tj] >= grid[i][j]){
						big = false;
						break;
					}else{
						firstval = max(firstval, grid[ti][tj]);
					}
				}
				if (big) grid[i][j] = firstval;
			}
		}
	}

	for(auto row: grid){
		for (auto c: row) cout << c << ' ';
		cout << '\n';
	}
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
