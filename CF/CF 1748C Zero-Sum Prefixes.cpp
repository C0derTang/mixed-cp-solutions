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
    vector<ll> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    int ans=0;
    ll sum = 0;
    map<ll, int> frq;
    map<int, set<ll>> rfrq;
    for(int i=n-1; i>-1; --i){
        sum += a[i];
        if(a[i]==0){
            if (!rfrq.empty()) ans += (*rfrq.rbegin()).first + (*rfrq.rbegin()).second.count(0);
            else ++ans;

            frq.clear();
            rfrq.clear();
            sum=0;
        }else{
            if(frq.count(sum)){
                rfrq[frq[sum]].erase(sum);
                if(rfrq[frq[sum]].empty()) rfrq.erase(frq[sum]);
            }
            ++frq[sum];
            rfrq[frq[sum]].insert(sum);
        }
    }
    ll pref=0;
    for(auto x: a){
        if (x==0) break;
        pref += x;
        ans += (pref==0);
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