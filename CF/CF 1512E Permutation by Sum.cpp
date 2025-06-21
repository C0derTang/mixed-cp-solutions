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
    // small n?
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    /*
    if (s > (n+n-(r-l))*n/2){
        cout << "-1\n";
    */
    set<int> avail, taken;
    int tsum = (r-l+1)*(r-l+2)/2;
    for(int i=0; i<r-l+1; ++i) taken.insert(i+1);
    for(int i=r-l+1; i<n; ++i) avail.insert(i+1);

    while(tsum < s){
        int dif = s-tsum;
        int tx=-1, ty=-1;
        int red = dif;
        for(auto x: taken){
            for(auto y: avail){
                if (dif - (y-x) < red && (y-x)<=dif && y-x>0){
                    red = dif - (y-x);
                    tx = x; ty = y;
                }
            }
        }
        if(tx != -1){
            taken.erase(tx);
            avail.insert(tx);
            avail.erase(ty);
            taken.insert(ty);
            tsum += ty-tx;
        }else{
            break;
        }
    }

    if(tsum != s){
        cout << "-1\n";
        return;
    }
    auto it = avail.begin();
    auto it2 = taken.begin();
    for(int i=0; i<n; ++i){
        if(i+1 >= l && i+1 <= r){
            cout << *it2;
            ++it2;
        }else{
            cout << *it;
            ++it;
        }
        cout << ' ';
    }
    cout << '\n';
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