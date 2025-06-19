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
    int n, d;
    cin >> n >> d;
    vector<int> s(n);
    for(int i=0; i<n; ++i) cin >> s[i];
    
    multiset<int> ns, p;
    for(int i=0; i<n; ++i){
        int x; cin >> x;
        p.insert(x);
    }

    s[d-1] += *p.rbegin();
    p.erase(p.find(*p.rbegin()));

    int ans=1;
    for(int i=0; i<n; ++i){
        if(i==d-1) continue;
        if(s[i] + *p.begin() > s[d-1]){
            ++ans;
            p.erase(p.find(*p.rbegin()));
        }
        else{
            p.erase(p.find(*p.begin()));
        }
    }
    cout << ans;
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
        solve();

}