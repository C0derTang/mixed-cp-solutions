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
    int n, m; cin >> n >> m;
	cout << "? 1 1" << endl;
    int d1; cin >> d1;
    if (d1==0){  cout << "! 1 1" << endl; return;}
    ++d1;
    cout << "? " << min(d1, n) << ' ' << min(d1, m) << endl;
    int d2; cin >> d2;
    if (d2==0){  cout << "! " << min(d1, n) << ' ' << min(d1, m) << endl; return;}
    cout << "? " << min(d1, n) << ' ' << min(d1, m)-d2 << endl;
    
    int d3; cin >> d3;
    if (d3==0) cout << "! " << min(d1, n) << ' ' << min(d1, m)-d2 << endl;
    else cout << "! " << min(d1, n)-d2 << ' ' << min(d1, m) << endl;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
