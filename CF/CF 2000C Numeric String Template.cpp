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

struct DSU {
    vector<int> roots;
    vector<int> sizes;
 
    void init(int n) {
        roots = vector<int>(n);
        sizes = vector<int>(n, 1);
        for (int i = 0; i < n; ++i) roots[i] = i;
    }
 
    int find(int x) {
        return roots[x] == x ? x : (roots[x] = find(roots[x]));
    }
 
    bool unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return false;
        if (sizes[rx] < sizes[ry]) swap(rx, ry);
        sizes[rx] += sizes[ry];
        roots[ry] = rx;
        return true;
    }

    bool linked(int x, int y) {return find(x) == find(y);}
};

void solve() {
    int n; cin >> n;
    vi a(n);
    F0R(i, n) cin >> a[i];
    int m; cin >> m;
    vector<string> s(m);
    F0R(i, m) cin >> s[i];

    
    for(auto cur: s){
        map<char, int> bash;
        map<int, char> bash2;
        if (cur.size() != n){
            cout << "NO\n";
            continue;
        }
        bool val = true;
        F0R(i, n){
            if ((bash.count(cur[i]) && bash[cur[i]] != a[i]) || (bash2.count(a[i]) && bash2[a[i]] != cur[i])){
                val = false;
                break;
            }
            bash[cur[i]] = a[i];
            bash2[a[i]] = cur[i];
        }
        cout << (val ? "YES\n": "NO\n");
    }
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
