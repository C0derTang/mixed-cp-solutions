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


int dsum(int x){
    int s=0;
    while(x){
        s += x%10;
        x /= 10;
    }
    return s;
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    set<int> big;
    for(int i=0; i<n; ++i) if(a[i] >= 10) big.insert(i);
    while(q--){
        int id; cin >> id;
        if(id == 1){
            int l, r; cin >> l >> r;
            --l; --r;
            auto it = big.lower_bound(l);
            while(it != big.end() && *it <= r){
                int idx = *it;
                a[idx] = dsum(a[idx]);
                if(a[idx] < 10) it = big.erase(it);
                else ++it;
            }
        }else{
            int x; cin>>x;
            --x;
            cout << a[x] <<'\n';
        }
    }
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