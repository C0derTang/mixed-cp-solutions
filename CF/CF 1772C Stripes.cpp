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
    vector<string> grid(8);
    for(int i=0; i<8; ++i) cin >> grid[i];

    for(int i=0; i<8; ++i){
        bool val = true;
        for(int j=0; j<8; ++j) if (grid[i][j] != 'R') val=false;
        if (val){
            cout << "R\n";
            return;
        }
    }

    for(int i=0; i<8; ++i){
        char cur = grid[0][i];
        if(cur == '.') continue;
        bool val = true;
        for(int j=0; j<8; ++j) if (grid[j][i] != 'B') val=false;
        if (val){
            cout << "B\n";
            return;
        }
    }

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