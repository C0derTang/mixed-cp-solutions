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
    //ok so for a value to be able to take over an array it must either be
    //smallest in prefix
    // largest in suffix
    // smaller than largest in suffix and has no smaller value before it
    // larger than smallest in prefix and has no larger value after it
    vector<int> pmin(n), smax(n);
    pmin[0] = a[0];
    for(int i=1; i<n; ++i) pmin[i] = min(a[i], pmin[i-1]);
    smax[n-1] = a[n-1];
    for(int i=n-2; i>-1; --i) smax[i] = max(a[i], smax[i+1]);

    vector<bool> ans(n);
    for(int i=0; i<n; ++i){
        if (a[i] == pmin[n-1] || a[i] == smax[0]) ans[i] = true;
        else if (a[i] > pmin[i] && a[i] == smax[i]) ans[i]=true;
        else if (a[i] < smax[i] && a[i] == pmin[i]) ans[i]=true;
        else if (i>0 && i<n-1 && a[i] < pmin[i-1] && a[i] > smax[i+1]) ans[i] = true; // 3 2 1 case
    }
    for(auto x: ans) cout << x;
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