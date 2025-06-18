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
    int n; cin>> n;
    string s; cin >> s;
    multiset<char> bef, aft;
    bef.insert(s[0]);
    for(int i=1; i<n; ++i) aft.insert(s[i]);
    for(int i=1; i<n-1; ++i){
        aft.erase(aft.find(s[i]));
        if (bef.find(s[i])!=bef.end() || aft.find(s[i])!=aft.end()){
            cout << "Yes\n";
            return;
        }
        bef.insert(s[i]);
    }
    cout << "No\n";
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