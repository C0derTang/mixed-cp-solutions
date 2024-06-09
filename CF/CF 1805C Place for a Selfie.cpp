#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    set<int> lines;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        lines.insert(k);
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        bool found = false;
        int disc = 4 * a * c;

        auto it = lines.lower_bound(b);
        if (it != lines.end()) {
            int k = *it;
            if ((b - k) * (b - k) < disc) {
                cout << "YES\n" << k << '\n';
                found = true;
            }
        }

        if (!found && it != lines.begin()) {
            it--;
            int k = *it;
            if ((b - k) * (b - k) < disc) {
                cout << "YES\n" << k << '\n';
                found = true;
            }
        }

        if (!found) {
            cout << "NO\n";
        }
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
