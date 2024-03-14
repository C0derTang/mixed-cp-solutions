#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cows[n];
	for (int i=0; i<n; ++i) {
		cin >> cows[i];
	}
	sort(cows, cows+n);

	int minmoves = 0;
	if(cows[n-2] - cows[0] == n-2 && cows[n-1] - cows[n-2] > 2){
		minmoves = 2;
	} else if(cows[n-1] - cows[1] == n-2 && cows[1] - cows[0] > 2){
		minmoves = 2;
	}else{
		int ans = 0;
		int r=0;
		for (int l=0; l<n; ++l) {
			
			while (r < n-1 && cows[r+1]-cows[l] <= n-1) {
				++r;
			}
			ans = max(ans, r-l+1);
		}
		minmoves = n-ans;
	}

	int maxmoves = max(cows[n-2] - cows[0], cows[n-1] - cows[1]) - (n-2);

	cout << minmoves << '\n' << maxmoves;
}
