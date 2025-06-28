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
    int n, x, y;
    cin >> n >> x >> y;
    
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    int sum = accumulate(a.begin(), a.end(), 0LL);
    sort(a.begin(), a.end());

    int ans=0;
     for(int i = 0; i < n - 1; ++i){
        auto l = lower_bound(a.begin() + i + 1, a.end(), sum - y - a[i]);
        auto r = upper_bound(a.begin() + i + 1, a.end(), sum - x - a[i]);

        ans += r-l;
    }
    cout << ans << '\n';

    //3 4 6 6
    // 6
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