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
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    if(n==k){
        for(int i=1; i<n; i+=2){
            if (a[i] != (i+1)/2){
                cout << (i+1)/2 << '\n';
                return;
            }
        }
        cout << k/2+1 << '\n';
        return;
    }
    
    for(int i=1; i<=n-k+1; ++i){
        if(a[i] != 1){
            cout << "1\n";
            return;
        }
    }
    cout << "2\n";
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