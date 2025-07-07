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
    int x, y, k;
    cin >> x >> y >> k;
    if(y==2){
        if(x==1){
            cout << "1\n";
            return;
        }
        while(k>0 && x != 1){
            if(!(x & 1)){ x++; --k; }    // make it odd
            else{
                x++; --k;
                while(!(x & 1)) x >>= 1; // strip all 2’s
            }
        }
        cout << (k>0 ? 1 : x) << '\n';
        return;
    }

    while(k>0 && x >= y){
        int dif = (y-1)-(x%y);
        if(k<dif){
            x += k;
            k=0;
            break;
        }
        x += dif;
        k -= dif;
        if(k==0) break;
        --k;
        ++x;
        while(x%y == 0) x /= y;
    }

    if (k > 0) {
        x = ((x - 1 + k) % (y - 1)) + 1;
    }

    cout << x << '\n';

    /*
    x += k;
    int l=1, r=pow(1e18, 1/y);
    while(l<r){
        int m = (l+r)/2;
        if(binexp(y, m) > x) r = m;
        else l = m+1;
    }
    cout << (x/binexp(y,l)) + x%(binexp(y,l)) << '\n';*/
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