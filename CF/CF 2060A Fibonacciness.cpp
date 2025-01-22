#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    vector<int> a(5);
    cin >> a[0] >> a[1] >> a[3] >> a[4];
    
    int maxans=0;
    for(int i=-400; i<401; ++i){
        a[2] = i;
        int ans = 0;
        for(int i=2; i<5; ++i) ans += (a[i-1]+a[i-2] == a[i]);
        maxans = max(ans, maxans);
    }
    cout << maxans << '\n';
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
