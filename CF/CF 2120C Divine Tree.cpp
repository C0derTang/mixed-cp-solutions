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
    int n, m;
    cin >> n >> m;
    // n nodes, 1-n
    // m target val
    // m <= n*(n+1)/2 bc tree with height < 2
    if(m > n*(n+1)/2){
        cout << "-1\n";
        return;
    }

    vector<pair<int, int>> pos(n+1);
    for(int i=1; i<n+1; ++i){
        pos[i].second=i;
        pos[i].first = n-i+1;
    }

    int curm = n*(n+1)/2;
    set<int> lmao;
    for(int i=1; i<n+1; ++i) lmao.insert(i);
    int tail=n+1;
    while(curm>m){
        int dif = curm-m;
        auto it = lmao.upper_bound(dif+1);
        if(it==lmao.begin()){
            cout << "-1\n";
            return;
        }
        if (*it == 1) {                   // moving 1 changes nothing
            cout << "-1\n";
            return;
        }
        --it;
        pos[*it].first=tail;
        ++tail;
        curm -= *it -1;
        lmao.erase(it);
    }
    if (curm != m) {                   // moving 1 changes nothing
            cout << "-1\n";
            return;
    }
    sort(pos.begin(), pos.end());
    cout << pos[1].second<< '\n';
    for(int i=1; i<n; ++i) cout << pos[i].second << ' ' << pos[i+1].second << '\n';
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