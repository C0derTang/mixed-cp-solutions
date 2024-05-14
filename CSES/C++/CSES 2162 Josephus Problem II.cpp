#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

//n, skip k elements, print k+1th until no more in array
// straight up simulating would be O(nk) or worse

//Possible Solutions
//Math: aks me

//Set bash?
// keep ordered set of all remaining numbers
// go through it and remove kth element
// ordered set orz

void solve(){
	int n, k;
	cin >> n >> k;
	ordered_set<int> kids;
	for(int i=1; i<=n; ++i) kids.insert(i);
	int pos = 0;
	while (!kids.empty()){
		pos %= kids.size();
		int exclude = (pos+k)%kids.size();
		pos = exclude;
		auto rip = kids.find_by_order(pos);
		cout << *rip << ' ';
		kids.erase(rip);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
