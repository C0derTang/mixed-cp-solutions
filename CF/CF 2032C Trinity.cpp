#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
	vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    int l=0, ans = n-2;
    for(int r=2; r<n; ++r){
        while(r-l >= 2 && a[l] + a[l+1] <= a[r]) ++l;
        ans = min(ans, n-(r-l+1));
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