#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);

	int n; cin >> n;
	vector<double> scores(n);
	for(int i=0; i<n; ++i){
		cin >> scores[i];
	}

	map<double, vector<int>> bash;
	double ming = scores[n-1];
	int curscore = scores[n-1];
	for(int i=n-2; i>0; --i){
		ming = min(ming, scores[i]);
		curscore += scores[i];
		bash[(curscore-ming)/(n-i-1)].push_back(i);
	}

	auto win = (*bash.rbegin()).second;
	sort(win.begin(), win.end());
	for (auto x: win) cout << x << '\n';
}
