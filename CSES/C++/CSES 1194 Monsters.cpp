#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

const int x[4] = {-1, 1, 0, 0};
const int y[4] = {0, 0, -1, 1};

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
	int n, m;
	cin >> n >> m;
	queue<pair<pair<int, int>, bool>> q;
	vector<vector<char>> grid(n, vector<char>(m));
	int starti, startj;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin >> grid[i][j];
			if (grid[i][j] == 'M') {q.push({{i, j}, false});}
			else if (grid[i][j] == 'A') {starti=i; startj=j;}
		}
	}
	q.push({{starti, startj}, true});

	while(!q.empty()){
		pair<pair<int, int>, bool> cur = q.front();
		q.pop();
		if (cur.second && (cur.first.first == 0 || cur.first.first == n-1 || cur.first.second == 0 || cur.first.second == m-1)){			
			int ci = cur.first.first;
			int cj = cur.first.second;
			vector<char> ret;
			while(grid[ci][cj] != 'A'){
				ret.push_back(grid[ci][cj]);
				if (grid[ci][cj] == 'L')++cj;
				else if (grid[ci][cj] == 'R')--cj;
				else if (grid[ci][cj] == 'D')--ci;
				else ++ci;
			}
			reverse(ret.begin(), ret.end());
			cout << "YES\n" << ret.size() << '\n';
			for(auto z: ret) cout << z;
			return 0;
		}

		for(int i=0; i<4; ++i){
			int tx = x[i]+cur.first.first;
			int ty = y[i] + cur.first.second;
			if(tx < 0 || tx >= n || ty < 0 || ty >= m || grid[tx][ty] != '.') continue;
			if (cur.second){
				if (x[i]==1) grid[tx][ty] = 'D';
				else if (x[i]==-1) grid[tx][ty] = 'U';
				else if (y[i]==1) grid[tx][ty]='R';
				else grid[tx][ty]='L';
			}else{
				grid[tx][ty] = 'M';
			}
			q.push({{tx, ty}, cur.second});
		}
	}
	cout << "NO";
}
