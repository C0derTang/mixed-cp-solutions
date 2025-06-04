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


void solve() {
    int n; cin >> n;
    string a, b;
    cin >> a >> b;

    int ae1 = 0, ao1 = 0;
    int be0 = 0, bo0 = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] == '1') {
            if (i%2) ++ao1;
            else ++ae1;
        }
        if(b[i]=='0'){
            if (i%2) ++bo0;
            else ++be0;
        }
    }
    if (ae1 <= bo0 && ao1 <= be0) cout << "YES\n";
    else cout << "NO\n";
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