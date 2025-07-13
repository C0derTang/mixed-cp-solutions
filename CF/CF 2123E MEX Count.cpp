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
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    vector<int> count(n+1);
    for(auto x: a) ++count[x];

    int mex=0;
    for(auto x: count) if(x==0) break; else ++mex;

    //cout << mex << '\n';

    vector<int> ans(n+2);
    for(int i=0; i<=mex; ++i){
        ++ans[count[i]];
        --ans[n+1-i];
    }
    for(int i=1; i<n+2; ++i) ans[i] += ans[i-1];
    for(int i=0; i<n+1; ++i) cout << ans[i] << ' ';
    cout << '\n';

    // separate into as many parts as possible
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