#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
pair<int, int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0; i<n; ++i) cin >> grid[i];
    vector<vector<bool>> seen(n, vector<bool>(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if (grid[i][j] != '1' || seen[i][j]) continue;
            int minx = n,  miny = m;
            int maxx = 0, maxy = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                minx = min(minx, cur.first);
                miny = min(miny, cur.second);
                maxx = max(maxx, cur.first);
                maxy = max(maxy, cur.second);
                seen[cur.first][cur.second] = true;
                for(auto move: dir){
                    int tx = cur.first+move.first;
                    int ty = cur.second+move.second;
                    if (tx>-1 && tx<n && ty>-1 && ty<m && !seen[tx][ty] && grid[tx][ty] == '1'){
                        seen[tx][ty] = true;
                        q.push({tx, ty});
                    }
                }
            }
            for(int ti=minx; ti<=maxx; ++ti){
                for(int tj = miny; tj<=maxy; ++tj){
                    if(grid[ti][tj] != '1'){
                        cout << "NO\n";
                        return;
                    }
                }
            }

        }
    }
    cout << "YES\n";
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}