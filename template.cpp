#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<pair<T, long long>, null_type, less<pair<T, long long>>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

const int dulo = 998244353;

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

ll fast_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
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

vector<ll> powers(1000001);

vector<ll> polyhash(string sr){
    vector<ll> ret(sr.size()+1);
    for(int i=0; i<sr.size(); ++i) ret[i+1] = (ret[i]+(sr[i]*powers[i]))%dulo;
    return ret;
}

void solve() {
    
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
