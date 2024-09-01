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

signed main() {
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);    
	int x, y, k, m;
	cin >> x >> y >> k >> m;
	if (y < x) swap(x, y);

	int ans=m;
	set<pii> cur;
	cur.insert({0,0});
	while(k--){
		set<pii> newcur;
		for(auto b: cur){
			if(b.first < x){
				newcur.insert({x, b.second});
				newcur.insert({min(x, b.second+b.first),max(0LL, b.second - (x-b.first))});
			}
			if (b.second < y){
				newcur.insert({b.first, y});
				newcur.insert({max(0LL, b.first - (y-b.second)),min(y, b.first+b.second)});
			}
			newcur.insert({0, b.second});
			newcur.insert({b.first, 0});
		}
		for(auto b: newcur){
			ans = min(ans, abs(m-(b.first+b.second)));
		}
		cur = newcur;
	}
	cout << ans;
}
