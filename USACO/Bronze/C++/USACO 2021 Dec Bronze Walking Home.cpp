#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int solve(){
	int n, k;
	cin >> n >> k;
	vector<string> grid(n);
	for (int i = 0; i < n; i++) cin >> grid[i];

	int ans = 0;

	if (k >= 1) {
		bool urcorner = true;
		bool dlcorner = true;
		for (int i = 0; i < n; i++) {
			if(grid[0][i] == 'H' || grid[i][n-1] == 'H') urcorner = false;
      		if(grid[i][0] == 'H' || grid[n-1][i] == 'H') dlcorner = false;
		}
		ans += urcorner;
		ans += dlcorner;
	}

	if (k >= 2) {
		for (int j = 1; j < n-1; j++) {
			bool valid = true;
			for (int i = 0; i < n; i++) {
				if (grid[i][j] == 'H') valid = false;
				if (i < j && grid[0][i] == 'H') valid = false;
				if (i > j && grid[n-1][i] == 'H') valid = false;
			}
			ans += valid;
		}

		for (int i = 1; i < n-1; i++) {
			bool valid = true;
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 'H') valid = false;
				if (j < i && grid[j][0] == 'H') valid = false;
				if (j > i && grid[j][n-1] == 'H') valid = false;
			}
			ans += valid;
		}
	}

	if(k >= 3) {
		for(int i = 1; i < n-1; i++) {
			for(int j = 1; j < n-1; j++) {
				// RDRD
				bool valid = grid[i][j] == '.';
				for(int a = 0; a < n; a++) {
					if(a <= i && grid[a][j] == 'H') valid = false;
					if(a >= i && grid[a][n-1] == 'H') valid = false;
					if(a <= j && grid[0][a] == 'H') valid = false;
					if(a >= j && grid[i][a] == 'H') valid = false;
				}
				ans += valid;
				valid = grid[i][j] == '.';
				// DRDR
				for(int a = 0; a < n; a++) {
					if(a <= i && grid[a][0] == 'H') valid = false;
					if(a >= i && grid[a][j] == 'H') valid = false;
					if(a <= j && grid[i][a] == 'H') valid = false;
					if(a >= j && grid[n-1][a] == 'H') valid = false;
				}
				ans += valid;
			}
		}
  }

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) cout << solve() << '\n';
}
