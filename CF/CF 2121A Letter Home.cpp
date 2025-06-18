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
    int n, s;
    cin >> n >> s;
    vector<int> x(n);
    for(int i=0; i<n; ++i) cin >> x[i];
    sort(x.begin(), x.end());
    ll ans=min(abs(s-x[0]), abs(s-x[n-1]));
    for(int i=1; i<n; ++i) ans += abs(x[i]-x[i-1]);
    cout << ans << '\n';

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