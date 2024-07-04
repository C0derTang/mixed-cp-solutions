#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)

void solve() {
    int m, x;
    cin >> m >> x;

    vi dp(100001, 5000000001);
    dp[0] = 0;

    int maxh = 0;
    FOR(i, 1, m+1){
        int c, h;
        cin >> c >> h;
        maxh += h;
        ROF(j, h, maxh+1){
            if (dp[j-h]+c <= (i-1)*x){
                dp[j]=min(dp[j], dp[j-h]+c);
            }
        }
    }

    R0F(i, maxh+1){
        if (dp[i] != 5000000001){
            cout << i << '\n';
            return;
        }
    }
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
