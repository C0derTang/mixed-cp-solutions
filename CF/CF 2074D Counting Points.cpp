#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n), r(n);
    for(int i=0; i<n; ++i) cin >> x[i];
    for(int i=0; i<n; ++i) cin >> r[i];
    map<int, int> maxheight;
    for(int i=0; i<n; ++i){
        for(int tx=-r[i]; tx<=r[i]; ++tx){
            maxheight[x[i]+tx] = max(maxheight[x[i]+tx], (int)sqrt((r[i]*r[i])-(tx*tx)));
        }
    }
    int ans=0;
    for(auto h: maxheight){
        //cout << h.first << ' ' << h.second << '\n';
        ans += 2*h.second + 1;
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