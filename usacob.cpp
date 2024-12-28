#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    // wtf is this time limit
    // this is kinda like dsu except we need to break connections?
    // since theres only r and d surely that means we can somehow prefix sum this
    // for fullsolve this has to be at most O(n^2q)
    // ok i think i got it
    // we keep track of how many cells point toward that one cell
    // and then for all the edge cells we can just multiply expected
    // O(n^2) update should be acceptable, we just dfs and update both sides
    // implementation is pain wtf
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<int> rval(n), dval(n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j) cin >> grid[i][j];
        cin >> rval[i];
    }
    for(int i=0; i<n; ++i) cin >> dval[i];
    
    vector<vector<int>> prop(n, vector<int>(n, 1));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if (grid[i][j] == 'R'){
                if (j+1 < n) prop[i][j+1] += prop[i][j];
            }else{
                if(i+1 < n) prop[i+1][j] += prop[i][j];
            }
        }
    }
    ll ans=0;
    for(int i=0; i<n; ++i) if(grid[i][n-1] == 'R') ans += prop[i][n-1]*rval[i];
    for(int i=0; i<n; ++i) if(grid[n-1][i] == 'D') ans += prop[n-1][i]*dval[i];
    cout << ans << '\n';
    
    int q; cin >> q;
    while(q--){
        int ti, tj;
        cin >> ti >> tj;
        --ti; --tj;
        grid[ti][tj] = (grid[ti][tj] == 'R') ? 'D':'R';
        int pval = prop[ti][tj];
        
        int pi = ti+(grid[ti][tj] == 'D');
        int pj = tj+(grid[ti][tj] == 'R');
        int ni = ti+(grid[ti][tj] == 'R');
        int nj = tj+(grid[ti][tj] == 'D');
        while(pi<n && pj<n) {
            prop[pi][pj] += pval;
            if (grid[pi][pj] == 'R') ++pj;
            else ++pi;
        }
        while(ni<n && nj<n) {
            prop[ni][nj] -= pval;
            if (grid[ni][nj] == 'R') ++nj;
            else ++ni;
        }
        ans = 0;
        for(int i=0; i<n; ++i) if(grid[i][n-1] == 'R') ans += prop[i][n-1]*rval[i];
        for(int i=0; i<n; ++i) if(grid[n-1][i] == 'D') ans += prop[n-1][i]*dval[i];
        cout << ans << '\n';
    }
}
