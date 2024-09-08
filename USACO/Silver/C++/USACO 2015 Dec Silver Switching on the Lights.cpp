#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


const int X[4] = {0,0,-1,1};
const int Y[4] = {-1,1,0,0};

signed main() {
    freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
    
	int n, m;
	cin >> n >> m;
	bool light[n][n]={};
	bool seen[n][n]={};
	vector<pair<int, int>> bash[n][n] = {};
	for(int i=0; i<m; ++i){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		--x; --y; --a; --b;
		bash[x][y].push_back({a,b});
	}

	light[0][0] = true;
	seen[0][0] = true;
	queue<pair<int, int>> q;
	q.push({0,0});
	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		for(auto x: bash[cur.first][cur.second]){
			if (!light[x.first][x.second]){
				light[x.first][x.second] = true;
				for(int i=0; i<4; ++i){
					int ti = X[i]+x.first;
					int tj = Y[i]+x.second;
					if(ti < 0 || ti >= n || tj < 0 || tj >= n || !seen[ti][tj]) continue;
					if(!seen[x.first][x.second]){
						seen[x.first][x.second] = true;
						q.push(x);
					}
					break;
				}
			}
		}
		for(int i=0; i<4; ++i){
			int ti = X[i]+cur.first;
			int tj = Y[i]+cur.second;
			if(ti < 0 || ti >= n || tj < 0 || tj >= n || seen[ti][tj] || !light[ti][tj]) continue;
			seen[ti][tj] = true;
			q.push({ti, tj});
		}
	}

	int ans=0;
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) ans += light[i][j];
	cout << ans;
}
