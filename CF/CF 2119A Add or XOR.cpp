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
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    if (b<a && (a^1) > b){
        cout << "-1\n";
        return;
    }

    int ans=0;
    if(a>b){
        a ^= 1;
        ans += y;
    }

    while(a<b){
        if ((long double)((a^1)-a)/y > (long double)1/x){
            a ^= 1;
            ans += y;
        }else{
            ++a;
            ans += x;
        }
    }
    //ans += (b-a)*x;
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