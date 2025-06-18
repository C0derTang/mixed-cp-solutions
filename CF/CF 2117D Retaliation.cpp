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
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    if (n == 2) {
        int a0 = a[0], a1 = a[1];
        bool val = false;
        for (int y=0; y<=a0/2; ++y) {
            int x = a0 - 2*y;
            if (x<0) continue;
            if (2*x + y == a1) {
                val = true;
                break;
            }
        }
        cout << (val ? "YES\n" : "NO\n");
        return;
    }
    
    int d = a[1] - a[0];
    bool val = true;
    for (int i=2; i<n; ++i) {
        if (a[i] - a[i-1] != d) {
            val = false;
            break;
        }
    }

    if (!val){
        cout << "NO\n";
        return;
    }

    //a[i] = (x-y) * (i+1) + y * (n+1)

    int c = a[0]-d;
    if (c % (n + 1) != 0) {
        cout << "NO\n";
        return;
    }

    cout << (c/(n+1) >=0 && d+c/(n+1) >=0 ? "YES\n" : "NO\n");
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