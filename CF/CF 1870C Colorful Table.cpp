#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

ll binexp(ll a, ll b){
    ll ret = 1;
    while (b>0){
        if (b&1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

ll modinv(ll a){
    return binexp(a, dulo-2);
}

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    // we need the index of the first element >= than x and the last element >= x for n elements x
    // we can go backwards bc its cumulative
    vector<vector<int>> pos(k+1);
    for(int i=0; i<n; ++i) pos[a[i]].push_back(i);
    vector<int> ans(k);
    int minw=1e5+1, maxw=0;
    for(int i=k; i>0; --i){
        if(pos[i].empty()) continue;
        for(auto x: pos[i]){
            minw = min(minw, x);
            maxw = max(maxw, x);
        }
        ans[i-1] = 2*(maxw-minw+1);
    }
    for(auto x: ans) cout << x << ' ';
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