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
    // if #0s <= k alice wins immediately
    // otherwise  uhhh look at 2nd tc
    // 1011011 k=4
    // 0001000
    // alice wins
    // last tc
    // 111111 k=4
    // 001100
    // so k > n/2?
    // what about like n=4k=2
    //1110 bob
    // 1101
    // 0100
    // surely just that condition

    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    int oc=0;
    for(auto c: s) oc += (c=='1');
    cout <<  (oc<=k || k>n/2 ? "Alice" : "Bob") << '\n';

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