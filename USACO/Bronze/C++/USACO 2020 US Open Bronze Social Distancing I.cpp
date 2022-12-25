#include <bits/stdc++.h>
#include <vector>
using namespace std;

int calc_dist(int n, vector<bool> arr){
	int ret = n+1;
	for (int i = 0; i < n; i++) {
		if (!arr[i]) continue;
		for (int j = i+1; j < n; j++) {
			if (!arr[j]) continue;
			ret = min(ret, j-i);
		}
	}
	return ret;
}

int main() {
	ifstream fin("socdist1.in");
	ofstream fout("socdist1.out");

	int n; fin >> n;
	string s; fin >> s;
	vector<bool> stalls(n, false);
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') stalls[i] = true;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (stalls[i]) continue;
		for (int j = i+1; j < n; j++) {
			if (stalls[j]) continue;
			stalls[i] = true;
			stalls[j] = true;
			ans = max(ans, calc_dist(n, stalls));
			stalls[i] = false;
			stalls[j] = false;
		}
	}
	
	fout << ans << '\n';
	
}
