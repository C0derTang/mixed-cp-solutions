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
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pii a, pii b) {
    return a.second < b.second;
}



void solve(){
	int n, m;
    cin >> n >> m;
    map<int, int> bash;
	vi a(n);
	F0R(i, n) cin >> a[i];
    F0R(i,n){
        int x; cin >> x;
        bash[a[i]] = x;
    }
    
    int ans=0;
    auto x = bash.begin();
    while(x != bash.end()){
        int tm=m;
        int curans = 0;
        auto y = x; ++y;
        int min1=min(tm/(x->first),x->second);
        curans += min1*(x->first);
        tm -= curans;
        if (y != bash.end() && (y->first) - (x->first) == 1){
            curans += min(tm/(y->first),y->second)*(y->first);
            int ttm=tm;
            tm -= min(tm/(y->first),y->second)*(y->first);
            curans += min(min(min1, tm), y->second - min(ttm/(y->first), y->second));
        }
        ans = max(ans, curans);
        ++x;
    }
    cout << ans << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}