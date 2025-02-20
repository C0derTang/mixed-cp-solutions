#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

ll fast_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

void solve(){
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    
    ll ans = 0;
    
    if(k == 1){
        ll low = max(l1, l2);
        ll high = min(r1, r2);
        ans = (low <= high) ? (high - low + 1) : 0;
        cout << ans << '\n';
        return;
    }
    
    for (ll t = 1; t <= r2; t *= k) {
        ll low_x = (l2 + t - 1) / t;  // ceil(l2 / t)
        ll high_x = r2 / t;           // floor(r2 / t)
        
        ll start = max(l1, low_x);
        ll end   = min(r1, high_x);
        
        if(start <= end)
            ans += (end - start + 1);
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