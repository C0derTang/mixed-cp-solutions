#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n, x;
    cin >> n >> x;
    ll max1 = 0, max2=0;
    while(n--){
        ll a; cin >> a;
        max1 = max(a, max1);
        max2 += a;
    }
    cout << max((max2+x-1)/x, max1) << '\n';
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
