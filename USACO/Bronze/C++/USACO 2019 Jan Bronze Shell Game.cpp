#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("shell.in");
	ofstream fout("shell.out");

	int n;
	fin >> n;
	vector<array<int, 3>> swaps(n);
	for (int i = 0; i < n; i++) {
		fin >> swaps[i][0] >> swaps[i][1] >> swaps[i][2];
	}

	int ans = 0;
	for (int start = 0; start < 3; start++) {
		int temp = 0;
		array<bool, 3> sim{};
		sim[start] = true;
		for (int i = 0; i < n; i++) {
			swap(sim[swaps[i][0]-1], sim[swaps[i][1]-1]);
			temp += sim[swaps[i][2]-1];
		}
		ans = max(ans, temp);
	}

	fout << ans << endl;

}
