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

bool cbs(pii a, pii b) {
    return a.second < b.second;
}
 

void solve() {
    int n; cin >> n;
	vi a(n);
    vector<vi> pos(n);
	F0R(i, n){
        cin >> a[i];
        pos[a[i]-1].push_back(i);
    }
	vi ans(n);
    vi ret(n, n+1);
    F0R(i, n){
        pos[i].push_back(-1LL);
        pos[i].push_back(n);
        sort(pos[i].begin(), pos[i].end());
        
        F0R(j, pos[i].size()-1) ans[i] = max(ans[i], pos[i][j+1]-pos[i][j]);
        if (ans[i] > 0 && ans[i] <= n) {if (i+1 < ret[ans[i]-1]) ret[ans[i]-1] = i+1;
}
        
    }
    if (ret[0] == n+1){
        ret[0] = -1;
    }
    cout << ret[0] << ' ';
    FOR(i, 1, n){
        if (ret[i] == n+1) ret[i] = ret[i-1];
        else if (ret[i-1] != -1) ret[i] = min(ret[i-1], ret[i]);
        cout << ret[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
