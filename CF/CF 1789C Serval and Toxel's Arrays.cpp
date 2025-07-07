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
    vector<int> a(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<int> count(n+m), last(n+m, -1);
    for(auto x: a){
        last[x] = 0;
        //count[x] = 1;
    }

    for(int i=0; i<m; ++i){
        int p, v;
        cin >> p >> v;
        --p; --v;
        if (a[p] != v){
            count[a[p]] += i-last[a[p]]+1;
            last[a[p]] = -1;
            last[v] = i+1;
            //++count[v];
            a[p] = v;
        }
    }

    for(int i=0; i<n+m; ++i) if (last[i] != -1) count[i] += m-last[i]+1;

    //for (auto x: count) cout << x << ' ';
    //cout << '\n';
    
    int ans=0;
    for(auto x: count) if(x > 0) ans += x*(m+1-x) + x*(x-1)/2;
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