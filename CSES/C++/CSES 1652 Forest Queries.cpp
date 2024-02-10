#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<string> forest(n);
	for (int i=0; i<n; ++i) {
		string row;
		cin >> forest[i];
	}

	vector<vector<int>> pref(n+1);
	for (int i=0; i<n+1; ++i) {
		pref[i] = vector<int>(n+1);
		for (int j=0; j<n+1; ++j) {
			pref[i][j] = 0;
			if (i==0 || j==0){
				continue;
			}
			if (forest[i-1][j-1] == '*') {
				++pref[i][j];
			}
			pref[i][j] += pref[i-1][j];
			pref[i][j] += pref[i][j-1];
			pref[i][j] -= pref[i-1][j-1];
		}
	}

	while (q--){
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << pref[y2][x2] - pref[y2][x1-1] - pref[y1-1][x2] + pref[y1-1][x1-1] << '\n';
	}

}