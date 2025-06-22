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
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (l1== l2 && l2 == l3){
        if(b1+b2+b3==l1){
            cout << "YES\n";
            return;
        }
    }
    if (b1== b2 && b2 == b3){
        if(l1+l2+l3==b1){
            cout << "YES\n";
            return;
        }
    }
    if (l3+l2==l1){
        if(b3==b2 && b1+b2==l1){
            cout << "YES\n";
            return;
        }
    }
    if (b3+b2==b1){
        if(l3==l2 && l1+l2==b1){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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