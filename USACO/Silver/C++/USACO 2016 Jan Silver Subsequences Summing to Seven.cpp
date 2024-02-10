#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int pref[n+1];
	pref[0] = 0;
	for (int i=0; i<n; ++i){
		int id; cin >> id;
		pref[i+1] = (pref[i] + id) % 7;
	}

	int firstOcc[7];
	fill(firstOcc, firstOcc+7, -1);

	long long ans = 0;
	for (int i=0; i<n+1; ++i){
		if (firstOcc[pref[i]] == -1){
			firstOcc[pref[i]] = i;
		}
		else{
			ans = max(ans, (long long)i - firstOcc[pref[i]]);
		}
	}
	cout << ans;
}
