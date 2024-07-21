#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vi a(n, -1);
    FOR(i, y-1, x) a[i] = 1;

    F0R(i, y-1) a[i] = (i%2 == (y-1)%2 ? 1 : -1);
    FOR(i, x, n) a[i] = (i%2 == (x-1)%2 ? 1 : -1);
    

    for(auto v: a) cout << v << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t; cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}
