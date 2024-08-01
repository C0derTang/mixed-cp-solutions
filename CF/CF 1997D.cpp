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

const int MAX = 1000000001;

//be minimalist. you struggled with implementation because your ass confused yourself
//with extra work. make sure everything you do makes sense before your ass implements.
//MINIMUM LEAF GOES ON TOP BRO
//if ur never gonna see a value again then dont update it?
//1:30 AM trippin balls dawg

int recurse(vi &a, vector<vi> &adj, int cur, int parent){
	if (adj[cur].size() == 1 && adj[cur][0] == parent) return a[cur];
	//distribute
	int minval = MAX;
	for (auto x: adj[cur]){
		if (x == parent) continue;
		minval = min(recurse(a, adj, x, cur), minval);
	}
	if (cur==0) return 0;
	if(minval > a[cur]){
		int avg = (minval+a[cur])/2;
		a[cur] = min(minval+a[cur]-avg, avg);
	}else{
		a[cur] = minval;
	}
	return a[cur];
}

void solve(){
	int n; cin >> n;
	vi a(n);
	F0R(i, n) cin >> a[i];
	vector<vi> adj(n);
	F0R(i, n-1){
		int x; cin >> x;
		adj[x-1].push_back(i+1);
		adj[i+1].push_back(x-1);
	}
	int ans = MAX;
	recurse(a, adj, 0, -1);
	for(auto x: adj[0]) ans = min(ans, a[x]);
	cout << a[0]+ans << '\n';
	
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}