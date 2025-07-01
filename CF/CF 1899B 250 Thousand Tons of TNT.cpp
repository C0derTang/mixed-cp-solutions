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
    vector<int> a(n), psum(n+1);
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) psum[i+1] = psum[i] + a[i];

    int ans=0;
    for(int i=1; i<=sqrt(n); ++i){
        if (n%i != 0) continue;
        int mins=1.5e15, maxs=0;
        for(int j=0; j<n; j+=i){
            mins = min(mins, psum[j+i]-psum[j]);
            maxs = max(maxs, psum[j+i]-psum[j]);
        }
        ans = max(ans, maxs-mins);
        mins=1.5e15, maxs=0;
        for(int j=0; j<n; j+=n/i){
            mins = min(mins, psum[j+n/i]-psum[j]);
            maxs = max(maxs, psum[j+n/i]-psum[j]);
        }
        ans = max(ans, maxs-mins);
    }
    cout << ans << '\n';
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