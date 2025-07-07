#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

int binexp(int a, int b){
    int ret = 1;
    while (b>0){
        if (b&1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int modinv(int a){
    return binexp(a, dulo-2);
}

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    int m; cin >> m;
    vector<vector<int>> lmao;
    for(int i=0; i<m; ++i){
        int n; cin >> n;
        lmao.push_back(vector<int>(n));
        for(int j=0; j<n; ++j) cin >> lmao[i][j];
    }

    vector<int> ans(m, -1);
    set<int> seen;
    for(int i=m-1; i>-1; --i){
        for(auto x: lmao[i]){
            if (!seen.count(x)){
                seen.insert(x);
                ans[i] = x;
            }
        }
        if(ans[i] == -1){
            cout << "-1\n";
            return;
        }
    }
    for(auto x: ans) cout << x << ' ';
    cout << '\n';
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