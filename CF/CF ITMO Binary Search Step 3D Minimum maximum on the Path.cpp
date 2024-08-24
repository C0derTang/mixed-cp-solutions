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

int n, m, d;
vector<vector<pii>> adj;
vi parent;

vi solve(int maxn) {
    queue<int> q;
    fill(parent.begin(), parent.end(), -1);
    int level = 0;
    q.push(0);

    while(!q.empty()) {
        if (level >= d) break;
        int temp = q.size();
        while (temp--) {
            int cur = q.front();
            q.pop();
            for (auto &x : adj[cur]) {
                if (x.second > maxn || parent[x.first] != -1) continue;
                q.push(x.first);
                parent[x.first] = cur;
                if (x.first == n - 1) {
                    vi ret;
                    int child = x.first;
                    while (child != -1) {
                        ret.push_back(child + 1);
                        child = parent[child];
                    }
                    reverse(ret.begin(), ret.end());
                    return ret;
                }
            }
        }
        ++level;
    }

    return {};
}


signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    cin >> n >> m >> d;
    adj.resize(n);
    parent.resize(n);
    F0R(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        adj[a].push_back({b, c});
    }

    int l=0, r=1000000001;
    while(l<=r){
        int mid = (l+r)/2;
        if (solve(mid).empty()){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }

    vi lmao = solve(l);
    if (lmao.empty()){
        cout << "-1";
        return 0;
    }
    cout << lmao.size()-1 << '\n';
    for(auto x: lmao) cout << x << ' ';
}
