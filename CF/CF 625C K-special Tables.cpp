#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

// why did i set bash unnecessarily

void solve(){
	int n, k;
	cin >> n >> k;
	set<int> nums;
	for(int i=1; i<=n*n; ++i) nums.insert(i);
	
	vector<vector<int>> ans(n, vector<int>(n));
	for(int i=0; i<n; ++i){
		for (int j=0; j<k-1; ++j){
			ans[i][j] = *nums.begin();
			nums.erase(nums.begin());
		}
		for(int j=n-1; j>=k-1; --j){
			auto it = nums.end();
			--it;
			ans[i][j] = *it;
			nums.erase(it);
		}
	}
	int sum = 0;
	for(int i=0; i<n; ++i) sum += ans[i][k-1];
	cout << sum << '\n';
	for(int i=0; i<n; ++i){
		for (auto x: ans[i]) cout << x << ' ';
		cout << '\n';
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
