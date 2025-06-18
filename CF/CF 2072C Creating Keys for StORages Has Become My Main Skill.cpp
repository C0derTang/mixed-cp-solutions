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
    ll n, x;
    cin >> n >> x;
    
    if(n==1){
        cout << x << '\n';
        return;
    }
    ll lmao = 0;
    ll cum=0;
    while(lmao+1 < n && (x|lmao) == x){
        cum |= lmao;
        cout << lmao << ' ';
        ++lmao;
    }
    if (lmao == n-1 && (cum|lmao) == x){
        cout << lmao << '\n';
        return;
    }
    while(lmao++ < n) cout << x << ' ';
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