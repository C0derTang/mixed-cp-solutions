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
    //1 3 5 7 9 11 13 15 17 19 21
    //2 6 10 14 18 22 26 30 34 38 42
    //oddx odd is fake news
    //4 12 20 28 36
    // 8 24 40
    // so its only powers of two lmao
    // odds are 2x+1
    // so p(2x+1) 
    int p = 1;
    while (true) {
        int cnt = (n/p + 1) / 2;
        if (k <= cnt) {
            cout << p * (2*k-1) << '\n';
            return;
        }
        k -= cnt;
        p *= 2;
    }
    cout << p+(p*2)*(k-1)<< '\n';
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