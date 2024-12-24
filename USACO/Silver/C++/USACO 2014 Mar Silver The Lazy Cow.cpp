#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(n)), psum(n, vector<int>(n+1));

    for(int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            cin >> grid[i][j];
            psum[i][j+1] = psum[i][j] + grid[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n+1; ++j){
            int curans = 0;
            for(int l=max(0, i-k); l <= min(n-1, i+k); ++l){
                curans += psum[l][min(n, j+(k-abs(i-l)))] - psum[l][max(0, j-(k-abs(i-l))-1)];
            }
            ans = max(ans, curans);
        }
    }

    // n^3 should fit the bounds.
    
    cout << ans;
}
