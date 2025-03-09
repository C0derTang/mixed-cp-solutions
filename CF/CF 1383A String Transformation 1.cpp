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
    return a.second > b.second;
}


void solve(){
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    for(int i=0; i<n; ++i){
        if (a[i] > b[i]){
            cout << "-1\n";
            return;
        }
    }
    map<char, set<char>> targets;
    map<char, set<int>> pos;
    for(int i=0; i<n; ++i){
        if(a[i] == b[i]) continue;
        pos[a[i]].insert(i);
        targets[a[i]].insert(b[i]);
    }
    
    int ans=0;
    for(auto x: targets){
        if (x.second.empty()) continue;
        char tgt = *(x.second.begin());
        char cur = x.first;
        for(auto y: pos[cur]){
            a[y] = tgt;
            if (a[y] != b[y]){
                pos[tgt].insert(y);
                targets[tgt].insert(b[y]);
            }
        }
        //targets.erase(cur);
        pos.erase(cur);
        ++ans;
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