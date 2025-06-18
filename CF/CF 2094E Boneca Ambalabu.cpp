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
    //instinct says make bitfreq array for all the values, then just sort by
    // (n-freq)value.
    int n; cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    vector<ll> freq(31);

    for(auto x: a){
        for(int i=0; i<31; ++i){
            freq[i] += (x>>i)&1;
        }
    }

    ll ans=0;
    for(auto x: a){
        ll curans=0;
        for(int i=0; i<31; ++i){
            if ((x>>i)&1) curans += (n-freq[i])*(1<<i);
            else if (freq[i]>0) curans += freq[i]*(1<<i);
        }

        ans = max(ans, curans);
    }

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