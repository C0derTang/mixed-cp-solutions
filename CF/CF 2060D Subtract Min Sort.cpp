#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    bool val = true;
    for(int i=1; i<n; ++i){
        if (a[i-1] == 0) continue;
        if(a[i-1] > a[i]){
            cout << "NO\n";
            return;
        }
        a[i] -= a[i-1];
        a[i-1] = 0;
    }
    cout << "YES\n";
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
