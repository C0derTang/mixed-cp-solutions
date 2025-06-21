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
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for(int i=0; i<n; ++i) cin >> c[i];

    bool f = true;
    int count=0;
    for(auto x: c){
        if(f){
            count += (x==c[0]);
            if(count==k){
                f=false;
                count=0;
            }
        }else{
            count += (x==c[n-1]);
            if(count==k){
                break;
            }
        }
    }
    cout << (count==k || (!f && c[0]==c[n-1]) ? "YES" : "NO") << '\n';
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