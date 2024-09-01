#include <bits/stdc++.h>
#include <cstdio>
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
    freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	int n; cin >> n;
	map<string, int> bash;
	int ans=0;
	F0R(i, n){
		string a, b;
		cin >> a >> b;
		a = a.substr(0,2);
		if (a != b)++bash[a+b];
	}
	for(auto x: bash){
		ans += bash[x.first.substr(2,2)+x.first.substr(0,2)]*x.second;
	}
	cout << ans/2;
}
