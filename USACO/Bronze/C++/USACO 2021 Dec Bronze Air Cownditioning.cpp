#include <bits/stdc++.h>
using namespace std;

int n;

bool all_zero(vector<int> arr){
	for (int i = 0; i < n; i++){
		if (arr[i] != 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	
	vector<int> end(n);
	vector<int> start(n);
	
	for (int i = 0; i < n; i++) cin >> end[i];
	for (int i = 0; i < n; i++) cin >> start[i];

	vector<int> dif(n);
	for (int i = 0; i < n; i++) dif[i] = end[i]-start[i];

	int first_nonzero = 0, ans = 0;
	while (true) {
		while (first_nonzero < n && dif[first_nonzero] == 0)
			++first_nonzero;
		if (first_nonzero == n)
			break;
		int r = first_nonzero;
		auto sgn = [&](int x) {
			if (x < 0)
				return -1;
			if (x > 0)
				return 1;
			return 0;
		};
		while (r + 1 < n && sgn(dif[r + 1]) == sgn(dif[first_nonzero]))
			++r;
		for (int i = first_nonzero; i <= r; ++i) {
			if (dif[i] < 0)
				++dif[i];
			else
				--dif[i];
		}
		++ans;
	}
	cout << ans << "\n";
}