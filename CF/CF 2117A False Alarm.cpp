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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    int l=0, r=n-1;
    while(l<n && a[l] != 1) ++l;
    while(r>-1 && a[r] != 1) --r;
    cout << (r == -1 || r-l+1 <= x ? "YES\n" : "NO\n");
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