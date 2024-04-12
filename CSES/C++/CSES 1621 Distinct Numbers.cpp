#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<ll> nums(n);
	for (int i=0; i<n; ++i) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	ll cur = nums[0];
	ll ans = 1;
	for (auto x: nums) {
		if (x != cur){
			++ans;
			cur = x;
		}
	}

	cout << ans;
}
