#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

ll binexp(ll a, ll b){
    ll ret = 1;
    while (b>0){
        if (b&1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

ll modinv(ll a){
    return binexp(a, dulo-2);
}

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin >> grid[i][j];

    set<int> once, twice;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if (twice.count(grid[i][j])) continue;
            once.insert(grid[i][j]);
            if((i>0 && grid[i-1][j]==grid[i][j]) || (i<n-1 && grid[i+1][j] == grid[i][j]) || (j>0 && grid[i][j-1]==grid[i][j]) || (j<m-1 && grid[i][j+1] == grid[i][j])){
                once.erase(grid[i][j]);
                twice.insert(grid[i][j]);
            }
        }
    }
    if (twice.empty()) cout << once.size()-1 << '\n';
    else cout << (twice.size()-1)*2 + once.size() << '\n';
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