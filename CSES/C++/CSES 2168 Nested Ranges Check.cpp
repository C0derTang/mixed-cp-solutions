#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define ll long long
 
bool cbs(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) return a[1] > b[1];
	return a[0] < b[0];
}
 
void solve(){
	int n; cin >> n;
	vector<vector<int>> intervals(n, vector<int>(3));
	for(int i=0; i<n; ++i){
		cin >> intervals[i][0] >> intervals[i][1];
		intervals[i][2] = i;
	}

	sort(intervals.begin(), intervals.end(), cbs);
	vector<int> contained(n);
	int largest = 0;
	for(int i=0; i<n; ++i){
		if (intervals[i][1] > largest){
			largest = intervals[i][1];
		}else{
			contained[intervals[i][2]] |= 1;
		}
	}

	vector<int> contains(n);
	int smallest = 1000000001;
	for(int i=n-1; i>-1; --i){
		if (intervals[i][1] < smallest){
			smallest = intervals[i][1];
		}else{
			contains[intervals[i][2]] |= 1;
		}
	}


	for(auto x: contains) cout << x << ' ';
	cout << '\n';
	for(auto x: contained) cout << x << ' ';
	cout << '\n';
}
 
signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t = 1;
	while(t--){
		solve();
	}
}