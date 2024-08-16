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
     int n, m, k;
    cin >> n >> m >> k;
    int w; cin >> w;
    vi a(w);
    F0R(i, w) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    vector<vi> increment(n + 1, vi(m + 1, 0));

    FOR(i, 0, n - k + 1) {
        FOR(j, 0, m - k + 1) {
            increment[i][j]++;
            increment[i + k][j]--;
            increment[i][j + k]--;
            increment[i + k][j + k]++;
        }
    }

    map<int, int>lmao;

    vector<vi> dp(n, vi(m, 0));
    F0R(i, n) {
        F0R(j, m) {
            dp[i][j] = increment[i][j];
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
            if (i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1];
            ++lmao[-dp[i][j]];
        }
    }

    int ans = 0;
    auto it = lmao.begin();
    for(auto x: a) {
        ans += -((*it).first) * x;
        --lmao[((*it).first)];
        if ((*it).second <= 0) ++it;
    }

    cout << ans << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
