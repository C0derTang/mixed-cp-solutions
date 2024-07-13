#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

// casually misses the O(1) math sol
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if(a>b){
        cout << n*a << '\n';
        return;
    }
    
    int ans = 0;
    int l=0, r=min(n,b);
    while(l<=r){
        int k=(l+r)/2;
        int curans = (n-k)*a;
        curans += b*k - (k-1)*k/2;
        ans = max(curans, ans);
        if(b-k+1 >= a){
            l = k+1;
        }else{
            r = k-1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
}
