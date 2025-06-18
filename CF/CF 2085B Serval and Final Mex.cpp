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
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    bool m1=false, m2=false;
    for(int i=0; i<(n)/2; ++i){
        if(a[i]==0){
            m1=true;
            break;
        }
    }
    for(int i=(n)/2; i<n; ++i){
        if(a[i]==0){
            m2=true;
            break;
        }
    }

    cout << m1+m2+1 << '\n';
    if(m2) cout << n/2+1 << ' ' << n << '\n';
    if(m1) cout << "1 " << n/2 << '\n';
    if(m1 && m2) cout << "1 2\n";
    else if (m1) cout << "1 " << (n+1)/2+1 << '\n';
    else if (m2) cout << "1 " << n/2+1 << '\n';
    else cout << "1 " << n << '\n';

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