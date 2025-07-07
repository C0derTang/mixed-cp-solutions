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
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    if(n&1){ // call me william lin
        cout << l << '\n';
        return;
    }
    if(n==2 || l==r){
        cout << "-1\n";
        return;
    }
    int p = 1;
    while(p <= l) p <<= 1;
    if(p > r){
        cout << "-1\n";
        return;
    }
    
    cout << (k <= n-2 ? l : p) << '\n';
    
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