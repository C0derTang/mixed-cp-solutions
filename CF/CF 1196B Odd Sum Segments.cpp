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
    for(int i=0; i<n; ++i) cin >> a[i];

    vector<int> ans;
    int lmao = k-1;
    int i=0;
    while(lmao && i<n){
        if (a[i]%2){
            --lmao;
            ans.push_back(i+1);
        }
        ++i;
    }
    if (lmao){
        cout << "NO\n";
        return;
    }
    while(i<n){
        lmao += a[i]%2;
        ++i;
    }
    if (lmao%2 == 0){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto x: ans) cout << x << ' ';
    cout << n << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}
