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
    vector<int> a(m);
    for(int i=0; i<m; ++i) cin >> a[i];

    sort(a.begin(), a.end());
            int l=0, r=m-1;

    for(int i=0; i<n; ++i){
        for(int j=0; j<6; ++j){
            if((i%2 && j%2==0) || (i%2==0 && j%2)){
                cout << a[r];
            }else{
                cout << a[l];
            }
            cout << ' ';
        }
        if (i%2 && i>0){
            ++l;
            --r;
            l%=n;
            if (r==m-n-1) r=m-1;
        }
        cout << '\n';
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