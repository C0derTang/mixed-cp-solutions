#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mOD(a, b) ((((a) % (b)) + (b)) % (b))

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
    int n; cin >> n;
    int px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    // lets rethink this shit uhh
    // required conditions
    // if dist <= sum of moves
    // whats the secondary???
    // d cant go any shorter than the longest one minus the others
    // d >= max(0, 2*longest - sum)
    //is this it???

    int dx = px - qx, dy = py - qy;
    int dist = dx*dx + dy*dy;
    int s  = accumulate(a.begin(), a.end(), 0LL);
    int m  = *max_element(a.begin(), a.end());
    int l  = max<int>(0, 2*m - s);

    bool val = (dist <= s*s) && (dist >= l*l);
    cout << (val ? "Yes\n" : "No\n");
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