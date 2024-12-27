#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    ll n; cin >> n;
    ll ans = 1;
    while(n > 3){
        n /= 4;
        ans *= 2;
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}
