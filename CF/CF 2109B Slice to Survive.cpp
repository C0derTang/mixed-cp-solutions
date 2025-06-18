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
    //cut so that the area is minimized. so just while true
    int n, m, a, b;
    cin >> n >> m >> a >> b;
 
    cout << min(min(ceil(log2(m-b+1)) + ceil(log2(n)), ceil(log2(b)) + ceil(log2(n))), min(ceil(log2(n-a+1)) + ceil(log2(m)), ceil(log2(a)) + ceil(log2(m))))+1 << '\n';
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