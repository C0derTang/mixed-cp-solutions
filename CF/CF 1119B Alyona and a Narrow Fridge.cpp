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

void solve(){
	int n, h;
	cin >> n >> h;
	vector<int> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	//sort(a.begin(), a.end());

	
	multiset<int> cur;
	bool val = true;
	for(int i=0; i<n; ++i){
		cur.insert(a[i]);
		int temp = h;
		int round = 0;
		for(auto it = cur.rbegin(); it != cur.rend(); ++it){
			if (round %2 == 0){
				if (temp - (*it) < 0){
					val = false;
					break;
				}
				temp -= *it;
			}
			++round;
		}
		if (!val) break;
	}
	cout << cur.size()-(!val);

}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t = 1;
	while(t--) solve();
}
