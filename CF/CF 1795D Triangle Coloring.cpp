#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))
const int dulo = 998244353;

ll binexp(ll a, ll b){
    ll ret = 1;
    while (b>0){
        if (b&1) ret  = (ret%dulo * a%dulo)%dulo;
        a = (a*a)%dulo;
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


signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);


    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n; cin >> n;
    vector<ll> fact(n/3+1);
    fact[0] = 1;
    //omgggg
    for(int i=1; i<n/3+1; ++i) fact[i] = ((fact[i-1]%dulo)*(i%dulo))%dulo;

    vector<int> w(n);
    for(int i=0; i<n; ++i) cin >> w[i];
    vector<int> ways;
    for(int i=0; i<n; i+=3){
        int cur=0;
        int minnum = min(w[i], min(w[i+1], w[i+2]));
        for(int j=i; j<i+3; ++j) cur += (w[j] == minnum);
        ways.push_back(cur);
    }

    //ok so this is ways without the constraint
    // so half of them have to be most red, and half have to be most blue
    // assume that they are all mostly red to begin with
    ll ans=1;
    for(int i=0; i<n/3; ++i){
        ans *= ways[i];
        ans %= dulo;
    }

    ll lmfao = (fact[n/3]%dulo*modinv(fact[n/6])%dulo*modinv(fact[n/6])%dulo)%dulo;
    cout << (ans*lmfao)%dulo;
}