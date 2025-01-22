#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> count;
    map<int, int> rcount;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        ++count[a[i]];
        ++rcount[k-a[i]];
    }
    int ans=0;
    for(auto x: count){
        //if (k-x.first == x.first) ans += x.second/2;
        ans += min(x.second, count[k-x.first]);
        //cout << min(x.second, count[k-x.first]) << ' ';
    }
    cout << ans/2 << '\n';
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
