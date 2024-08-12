#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<pair<T, long long>, null_type, less<pair<T, long long>>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(k), t(k);
    F0R(i, k) cin >> a[i];
    F0R(i, k) cin >> t[i];

    vector<pii> pairs(k);
    F0R(i, k) pairs[i] = {a[i], t[i]};
    sort(pairs.begin(), pairs.end());

    F0R(i, k) {
        a[i] = pairs[i].first;
        t[i] = pairs[i].second;
    }


    vi ans(n, *max_element(t.begin(), t.end())+n);

    for (int i = 0, j = 0; i < n; i++) {
        if (j < k && a[j] - 1 == i) {
            ans[i] = t[j++];
        }
        if (i > 0) {
            ans[i] = min(ans[i], ans[i - 1] + 1);
        }
    }

    for (int i = n - 1, j = k - 1; i >= 0; i--) {
        if (j >= 0 && a[j] - 1 == i) {
            ans[i] = min(ans[i], t[j--]);
        }
        if (i < n - 1) {
            ans[i] = min(ans[i], ans[i + 1] + 1);
        }
    }

    for (auto l : ans) cout << l << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        solve();
    }
}
