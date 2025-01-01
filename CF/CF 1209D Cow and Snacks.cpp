#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

struct DSU {
    vector<int> roots;
    vector<int> sizes;
 
    void init(int n) {
        roots = vector<int>(n);
        sizes = vector<int>(n, 1);
        for (int i=0; i<n; ++i) roots[i] = i;
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


signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    // first doesnt matter
    // for a componentafter first pick only the ones that have 1 overlap with the other ones.
    // a component with x candies can only support x-1 cows
    // size of components lmfao dsu bash
    DSU uf;
    uf.init(n);
    for(int i=0; i<k; ++i){
        int a, b;
        cin >> a >> b;
        --a; --b;
        uf.unite(a, b);
    }
    // so surely its just k - sum(component size - 1)
    vector<int> smax(n);
    for(int i=0; i<n; ++i){
        int comp = uf.find(uf.roots[i]);
        smax[comp] = max(smax[comp], uf.sizes[comp]-1);
    }

    cout << k-accumulate(smax.begin(), smax.end(), 0LL);
}
