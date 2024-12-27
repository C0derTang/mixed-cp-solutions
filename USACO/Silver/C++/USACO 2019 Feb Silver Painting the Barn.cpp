#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
const int MAXN = 1001;

signed main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(MAXN, vector<int>(MAXN));
    while(n--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++grid[x1][y1];
        --grid[x2][y1];
        --grid[x1][y2];
        ++grid[x2][y2];
    }
    int ans=0;
    for(int i=0; i<1000; ++i){
        for(int j=0; j<1000; ++j){
            if (i) grid[i][j] += grid[i-1][j];
            if (j) grid[i][j] += grid[i][j-1];
            if (i && j)grid[i][j] -= grid[i-1][j-1];
            if(grid[i][j] == k) ++ans;
        }
    }
    cout << ans;
}
