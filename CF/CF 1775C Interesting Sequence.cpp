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
    // you can only remove bits
    // if any bit in x is set that isnt in n, reject
    if (x>n){
        cout << "-1\n";
        return;
    }
    // if the first difference in bits
    // find largest unset bit in x
    int largest=-1;
    for(int i=0; i<64; ++i){
        if (((x>>i)&1) && !((n>>i)&1)){
            cout << "-1\n";
            return;
        }
        if(((n>>i)&1) && !((x>>i)&1)) largest = i;
    }
    if(largest == -1){
        cout << n << '\n';
        return;
    }
    while ((n>>largest)&1) ++largest;
    if(x != 0 && largest > 63-__builtin_clzll(n)){
        cout << "-1\n";
        return;
    }
    ll ans = (1LL<<largest);
    for(int i=largest+1; i<64; ++i){
        if(((n>>i)&1LL)) ans += 1LL<<i;
    }
    for(int i=0; i<largest; ++i){
        if(((x>>i)&1LL)){
            cout << "-1\n";
            return;
        }
    }
    cout << (ans > n ? ans : -1) << '\n';
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