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
    string l, r;
    cin >> l >> r;
    ll ans=0;
    string s;
    for(int i=0; i<r.size()-l.size(); ++i) s += '0';
    s += l;
    bool prev=false;
    for(int i=0; i<r.size(); ++i){
        if(prev || (i>0 && r[i-1]!=s[i-1])){
            ans += 9;
            prev=true;
        }
        else ans += abs((r[i]-'0')-(s[i]-'0'));
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