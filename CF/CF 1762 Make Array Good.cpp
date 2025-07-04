#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

int binexp(int a, int b){
    int ret = 1;
    while (b>0){
        if (b&1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int modinv(int a){
    return binexp(a, dulo-2);
}

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    // surely most optimal is to get each number to the closest power of 2 right
    int big = *max_element(a.begin(), a.end());
    vector<pair<int, int>> ans;
    for(int i=0; i<n; ++i){
        int close = 1;
        while(close < a[i]) close <<= 1;
        if(close-a[i] == 0) continue;
        else ans.push_back({i+1, close-a[i]});
    }
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x.first << ' ' << x.second << '\n';
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