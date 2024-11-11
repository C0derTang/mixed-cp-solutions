#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int k, x, a;
	cin >> k >> x >> a;

    // so we find minimum k^n that is greater than all possible losses and check if we have enough initial coins to fail like that
    int profit=0, bet=1;
    while(x--){
        profit -= bet;
        a -= bet;
        if (a <= 0){
            cout << "NO\n";
            return;
        }
        bet = max(1, (int)(-profit / (k - 1)) + 1);

        //cout << profit << ' ' << bet << ' ' << a << '\n';
    }
    cout << (a >= bet ? "YES\n" : "NO\n");
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
