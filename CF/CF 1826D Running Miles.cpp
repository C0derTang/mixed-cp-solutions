#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    vector<int> b(n), pmax(n), smax(n);
    for(int i=0; i<n; ++i){
        cin >> b[i];
        pmax[i] = b[i]+i;
        smax[i] = b[i]-i;
    }
    for(int i=1; i<n; ++i) pmax[i] = max(pmax[i], pmax[i-1]);
    for(int i=n-2; i>-1; --i) smax[i] = max(smax[i], smax[i+1]);

    int ans=0;
    for(int i=1; i<n-1; ++i) ans = max(ans, b[i] + pmax[i-1]+smax[i+1]);
    cout << ans << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
