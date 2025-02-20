#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k+1), b(k+1);
    a[0] = b[0] = 0;
    for(int i=1; i<k+1; ++i) cin >> a[i];
    for(int i=1; i<k+1; ++i) cin >> b[i];

    while(q--) {
        int d;
        cin >> d;
        // Find the largest index i such that a[i] <= d using upper_bound.
        int idx = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
        // If the query is exactly at a known sign or it's the final destination,
        // output the known time.
        if(d == a[idx] || idx == k) {
            cout << b[idx] << " ";
        } else {
            // Compute the additional time needed in the current interval.
            int deltaA = a[idx+1] - a[idx];
            int deltaB = b[idx+1] - b[idx];
            int traveled = d - a[idx];
            // Multiply first (using 64-bit arithmetic) then divide.
            int add_time = (traveled * deltaB) / deltaA;
            int ans = b[idx] + add_time;
            cout << ans << " ";
        }
    }
    cout << "\n";
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