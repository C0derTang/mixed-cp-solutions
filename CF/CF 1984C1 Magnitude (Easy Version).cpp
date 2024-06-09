#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int max_c = 0, min_c = 0;
    for (int i = 0; i < n; ++i) {
        int new_max_c = max(max_c + a[i], min_c + a[i]);
        int new_min_c = min(max_c + a[i], min_c + a[i]);
        max_c = max(new_max_c, abs(new_min_c));
        min_c = min(new_min_c, abs(new_min_c));
    }
    
    cout << max_c << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
