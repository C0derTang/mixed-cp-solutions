#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    int n; cin >> n;
    vector<int> b(2*n);
    for(auto &x : b) cin >> x;
    sort(b.begin(), b.end());
    int x =  accumulate(b.begin()+n-1, b.end(), 0LL)-accumulate(b.begin(), b.begin()+n-1, 0LL);
    cout << b.back() << ' ' << x << ' ';
    for(int i=0; i<n; ++i){
        if (i != n-1) cout << b[i+n] << ' ';
        cout << b[i] << ' ' ;
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