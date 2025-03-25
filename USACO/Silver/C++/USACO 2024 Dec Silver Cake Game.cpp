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
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    vector<ll> pref(n+1), suff(n+1);
    for(int i=0; i<n; ++i) pref[i+1] = pref[i] + a[i];
    //for(auto x: pref) cout << x << ' ';
    //cout << '\n';
    ll eans=0;
    for(int i=0; i<n/2; ++i){
        eans = max(eans, pref[n]-pref[i+n/2+1]+pref[i]);
    }
    cout << pref[n]-eans << ' ' << eans;
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
        if(t>0) cout << '\n';
    }
}