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
#define double long double
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

void solve(){
    int n;
    cin >> n;
    
    vector<pair<int, int>> circles(n);
    FOR(i, 0, n) {
        int xi, yi;
        cin >> xi >> yi;
        circles[i] = {xi, yi};
    }
    
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    
    auto dist = [](int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    
    int ptttime = dist(xs, ys, xt, yt);
    
    for (int i = 0; i < n; ++i) {
        int ttctime = dist(xt, yt, circles[i].first, circles[i].second);
        
        if (ptttime >= ttctime) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}