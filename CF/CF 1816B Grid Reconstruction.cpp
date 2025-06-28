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
    int n; cin >> n;
    // ok n is even means this is free
    int lmao=2*n;
    vector<vector<int>> ans(2, vector<int>(n));
    for(int i=0; i<n; i+=2){
        ans[0][i] = 2*n-i;
        ans[1][i] = 1+i;
    }
    for(int i=n-1; i>-1; i-=2){
        ans[0][i] = i+1;
        ans[1][i] = n+i;
    }


    for(auto x: ans){
        for(auto y: x) cout << y << ' ';
        cout << '\n';
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