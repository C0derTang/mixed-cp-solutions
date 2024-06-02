#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

void solve() {
    int n; 
    cin >> n;
    vector<char> a(n), b(n);
    vector<int> ans;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            if (a[0] == b[i]) {
                a[0] = (a[0] == '0') ? '1' : '0';
                ans.push_back(1);
            }
            for (int j = 0; j <= i / 2; ++j) {
                swap(a[j], a[i - j]);
                a[j] = (a[j] == '0') ? '1' : '0';
                if (j != i - j) {
                    a[i - j] = (a[i - j] == '0') ? '1' : '0';
                }
            }
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << ' ';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t; // = 1;
    while (t--) {
        solve();
    }
}
