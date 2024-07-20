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
	int n,k,a,b;
	cin >> n >> k >> a >> b;
	--a; --b;
	vector<pii> cities(n);
	F0R(i, n) cin >> cities[i].first >> cities[i].second;

	int closea=4000000000;
	F0R(i, k) closea = min(closea, abs(cities[i].first-cities[a].first) + abs(cities[i].second-cities[a].second));
	int closeb=4000000000;
	F0R(i, k) closeb = min(closeb, abs(cities[i].first-cities[b].first) + abs(cities[i].second-cities[b].second));

	cout << min(closea+closeb, abs(cities[b].first-cities[a].first) + abs(cities[b].second-cities[a].second)) << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
