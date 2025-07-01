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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<pair<int, int>> b=a;
    sort(b.begin(), b.end());
    vector<int> cheese(n);
    int idx=0;
    while(k>0){
        if (k<=m){
            cheese[b[idx].second] = k;
            break;
        }else{
            cheese[b[idx].second] = m;
            k -= m;
            ++idx;
        }
    }
    /*
    cout << "cheese\n";
    for(auto x: cheese) cout << x << ' ';
    cout << '\n';*/
    int ans=0;
    int byprod=0;
    for(int i=0; i<n; ++i){
        ans += cheese[i]*(a[i].first+byprod);
        byprod += cheese[i];
        //cout << ans << ' ';
    }
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