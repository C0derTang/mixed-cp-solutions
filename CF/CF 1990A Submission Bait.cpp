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

void solve(){
    int n; cin >>n;
   vi a(51);
   F0R(i, n){
       int x; cin >> x;
       ++a[x];
   }
   FOR(i, 1, 51){ if (a[i]%2) {cout << "YES\n"; return;}}
   cout << "NO\n";
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; 
    cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}
