#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 1e9+7;

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

vector<int> fct(1e5+1, 1);
void pcmp(){
    for(int i=1; i<1e5+1; ++i) fct[i] = (fct[i-1]*i)%dulo;
}

void solve(){
    int n; cin >> n;
    int ans=0;
    for(int i=2; i<=n; ++i){
        ans += 2*fct[n]*(i-1)%dulo;
        //ans += (2*n*(i-1))%dulo;
    }
    cout << ans%dulo << '\n';
    //1 2 2 1
    //2 1 1 2

    //1 2 3 3 2 1
    //1 3 2 2 3 1
    //2 1 3 3 1 2
    //2 3 1 1 3 2
    //3 1 2 2 1 3
    //3 2 1 1 2 3

}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    pcmp();
    int t; cin >> t;
    while(t--){
        solve();
    }
}