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
    int n; cin >> n;
    vector<int> b(n+2);
    for(int i=0; i<n+2; ++i) cin >> b[i];
    sort(b.begin(), b.end());

    int sum = b[n+1];
    int rsum = accumulate(b.begin(), b.end(), 0LL);
    rsum -= sum;
    for(int i=0; i<n+1; ++i){
        if (rsum-b[i] == sum){
            for(int j=0; j<n+1; ++j){
                if (j==i) continue;
                cout << b[j] << ' ';
            }
            cout << '\n';
            return;
        }
    }

    rsum += sum;
    sum = b[n];
    rsum -= sum;
    for(int i=0; i<n+2; ++i){
        if (i==n) continue;
        if (rsum-b[i] == sum){
            for(int j=0; j<n+1; ++j){
                if (j==i || j==n) continue;
                cout << b[j] << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << "-1\n";
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