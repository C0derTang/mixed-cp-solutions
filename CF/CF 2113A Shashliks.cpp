#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve() {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;

    if (k < a && k < b) {
        cout << "0\n";
        return;
    }

    int cnt1 = 0, cnt2 = 0;
    int temp = k;
    if (temp >= a) {
        cnt1 = (temp-a) / x + 1;
        temp -= cnt1 * x;
    }
    if (temp >= b) {
        cnt2 = (temp-b) / y + 1;
    }
    int t1first = cnt1 + cnt2;

    cnt1 = cnt2 = 0;
    temp = k;
    if (temp >= b) {
        cnt2 = (temp-b) / y + 1;
        temp -= cnt2 * y;
    }
    if (temp >= a) {
        cnt1 = (temp-a) / x + 1;
    }
    int t2first = cnt1 + cnt2;

    cout << max(t1first, t2first) << '\n';
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