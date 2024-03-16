#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, g;
	cin >> n >> g;
	vector<vector<int>> mods(n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<3; ++j) {
			int x; cin >> x;
			mods[i].push_back(x);
		}
	}
	sort(mods.begin(), mods.end());
	
	map<int, int> cows;
	for (auto m: mods){
		cows[m[1]] = g;
	}

	map<int, int> count = {{g,n}};
	int changes = 0;
	for (auto m: mods){
		int milk = cows[m[1]];
		bool prev_best = milk == count.rbegin()->first;
		int prev_count = count[milk];

		--count[milk];
		if (count[milk] == 0) {
			count.erase(milk);
		}
		milk += m[2];
		++count[milk];
		cows[m[1]] = milk;
		bool new_best = milk == count.rbegin()->first;
		int new_count = count[milk];

		if (prev_best){
			if (new_best && prev_count == new_count) continue;

			++changes;
		} else if(new_best){
			++changes;
		}
	}
	cout << changes;
}