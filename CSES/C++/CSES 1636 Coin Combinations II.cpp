#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1000000007;

// using #define int long long requires way too much storage

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i - 1][j]; // ways without using the new coin
            if (j >= coins[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i][j - coins[i - 1]]) % MOD;
            }
        }
    }

    cout << dp[n][x] << '\n';
    return 0;
}
