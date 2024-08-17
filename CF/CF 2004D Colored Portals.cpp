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
    int n, q;
    cin >> n >> q;
    vi colors(n);
    map<int, vi> bash;
    F0R(i, n){
        string s; cin >> s;
        for(auto x:s){
            if (x=='B') colors[i] |= 1;
            if (x=='R') colors[i] |= 2;
            if (x=='G') colors[i] |= 4;
            if (x=='Y') colors[i] |= 8;
        }
        bash[colors[i]].push_back(i);
    }
/*
    for(auto x: colors) cout << x << ' ';
    cout << '\n';
    for(auto x: bash){
        cout << x.first << ": ";
        for(auto y: x.second) cout << y << ' ';
        cout << '\n';
    }
*/

    while(q--){
        int x, y;
        cin >> x >> y;
        --x; --y;
        if (colors[x] & colors[y]){
            cout << abs(y-x) << '\n';
            continue;
        }

        int ans = 600000;
        FOR(i, 1, 16){
            int a = i&colors[x], b = i&colors[y];
            if (__builtin_popcount(a)==1 && __builtin_popcount(b)==1){
                if (bash[i].empty()) continue;
                auto best= lower_bound(bash[i].begin(), bash[i].end(), min(x, y));
                if (best == bash[i].end()) --best;
                ans = min(ans, abs(x-*best) + abs(y-*best));
                if (best != bash[i].begin()){
                    --best;
                    ans = min(ans, abs(x-*best) + abs(y-*best));
                }
                
            }
        }
        cout << (ans==600000 ? -1 : ans) << '\n';
    }
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
