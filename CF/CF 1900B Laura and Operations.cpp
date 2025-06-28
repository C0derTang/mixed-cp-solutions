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
    int a, b, c;
    cin >> a >> b >> c;
    //1 1 2 3 3
    // 1 3 3 3
    // 2 3 3
    // 1 3
    // 2
    // 1 1 1 3
    // 1 1 2
    // 1 3
    // 2
    // the one with different parity is the one that is possible unless theyre all the same
    if(a%2 == b%2 && a%2 == c%2){
        cout << "1 1 1\n";
    }else if (a%2 != b%2 && b%2==c%2){
        cout << "1 0 0\n";
    }else if (b%2 != a%2 && a%2==a%2){
        cout << "0 1 0\n";
    }else{
        cout << "0 0 1\n";
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