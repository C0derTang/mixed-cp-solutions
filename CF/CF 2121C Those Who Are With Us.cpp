#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

ll binexp(ll a, ll b){
    ll ret = 1;
    while (b>0){
        if (b&1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

ll modinv(ll a){
    return binexp(a, dulo-2);
}

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> rowsum(n),colsum(m);
    int maxval=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> a[i][j];
            maxval = max(maxval, a[i][j]);
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(a[i][j] == maxval){
                ++rowsum[i];
                ++colsum[j];
            }
        }
    }


    int maxi=0, maxj=0, maxsum=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(rowsum[i]+colsum[j]- 1*(a[i][j] == maxval)  > maxsum){
                maxsum=rowsum[i]+colsum[j]-1*(a[i][j] == maxval);
                maxi=i;
                maxj=j;
            }
        }
    }

    for(int i=0; i<n; ++i) --a[i][maxj];
    for(int j=0; j<m; ++j) --a[maxi][j];
    ++a[maxi][maxj];
    
    int ans=0;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) ans = max(ans, a[i][j]);
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