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
    int n, m;
    cin >> n >> m;
    multiset<int> a, b;
    for(int i=0; i<n; ++i){
        int x; cin >> x;
        a.insert(x);
    }
    for(int i=0; i<m; ++i){
        int x; cin >> x;
        if(a.find(x) != a.end()) a.erase(a.find(x));
        else b.insert(x);
    }

    while(true){
        int pas = a.size();
        int pbs = b.size();
        while(!a.empty() && !b.empty() && a.find(*b.begin()) != a.end()){
            a.erase(a.find(*b.begin()));
            b.erase(b.begin());
        }
        if (a.empty() || b.empty()) break;

        int x = *b.begin();
        if(x==1) break;
        b.erase(b.find(x));
        b.insert(x/2);
        b.insert((x+1)/2);

        if (pas == a.size() && pbs == b.size()){
            cout << "No\n";
            return;
        }
    }
    cout << (a.empty() && b.empty() ? "Yes\n" : "No\n");
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