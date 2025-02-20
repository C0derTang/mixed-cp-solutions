#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
    int n; cin >> n;
    vector<bool> seen(n+1);
    cout << "1 ";
    for(int i=2; i<=n; ++i){
        if (seen[i]) continue;
        for(int j=i; j<=n; j*=2){
            if (seen[j]) continue;
            seen[j] = true;
            cout << j << ' ';
        }
    }
    cout << '\n';
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