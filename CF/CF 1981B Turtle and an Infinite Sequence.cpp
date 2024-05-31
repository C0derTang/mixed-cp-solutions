#include <bits/stdc++.h>
using namespace std;

#define ll long long

int getmsb(ll int N) {
    int msb_p = -1;
    while (N) {
        N = N >> 1;
        msb_p++;
    }
    return msb_p;
}

ll findBitwiseOr(ll l, ll r) {
    ll res = 0;

    int msb_p1 = getmsb(l);
    int msb_p2 = getmsb(r);

    while (l != 0 && r != 0 && msb_p1 == msb_p2) {
        ll int res_val = (1ll << msb_p1);

        res += res_val;

        l -= res_val;
        r -= res_val;

        msb_p1 = getmsb(l);
        msb_p2 = getmsb(r);
    }

    msb_p1 = max(msb_p1, msb_p2);

    for (int i = msb_p1; i >= 0; i--) {
        ll int res_val = (1ll << i);
        res += res_val;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll start = max(0ll, n - m);
    ll end = n + m;

    ll result = findBitwiseOr(start, end);

    cout << result << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}