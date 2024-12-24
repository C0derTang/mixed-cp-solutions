#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    vector<int> pref = a, suff = a;
    for(int i=1; i<n; ++i) pref[i] = __gcd(pref[i], pref[i-1]);
    for(int i=n-2; i>-1; --i) suff[i] = __gcd(suff[i], suff[i+1]);

    
    int ans = max(pref[n-2], suff[1]);
    for(int i=0; i<n-2; ++i) {
        ans = max(ans, __gcd(pref[i], suff[i+2]));
        //cout << pref[i] << ' ' << suff[i+1] << '\n';
    }
    cout << ans;
}