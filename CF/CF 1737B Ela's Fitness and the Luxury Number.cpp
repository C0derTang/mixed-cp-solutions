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
set<ll> primes;

void solve(){
    ll l, r; cin >> l >> r;
    ll rsq = floor(sqrtl(r));
    ll lsq = floor(sqrtl(l));
    ll ans = (rsq-lsq+1)*3;
    for(int i=lsq; i<lsq+3; ++i) if (lsq*i < l) --ans;
    for(int i=rsq; i<rsq+3; ++i) if (rsq*i > r) --ans;

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