#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pint;

int main() {
	// defining vars
	int n;
	cin >> n;
	int pref[n+1][n+1];
	for (int i=0; i<n+1; ++i){
		for (int j=0; j<n+1; ++j){
			pref[i][j] = 0;
		}
	}
	pint points[n];
	for (int i=0; i<n; ++i){
		int x, y; cin >> x >> y;
		points[i] = make_pair(x, y);
	}

	// coord compression
	sort(points, points+n);
	for (int i = 0; i < n; ++i){
		points[i].first = i+1;
	}
	sort(points, points + n, [](pint p, pint q) {return p.second < q.second;});
	for (int i=0; i<n; ++i){
		points[i].second = i+1;	}

	// make prefix sum
	for (int i=0; i<n; ++i){
		++pref[points[i].first][points[i].second];
	}
	for (int i=1; i<n+1; ++i){
		for (int j=1; j<n+1; ++j){
			pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
		}
	}

	// calc answer
	long long ans = n+1;
	for (int i=0; i<n; ++i){
		for (int j=i+1; j<n; ++j){
			int x1 = min(points[i].first, points[j].first)-1;
			int x2 = max(points[i].first, points[j].first)-1;
			// 0, i, x1, j
			// x2 i n-1 j
			// x1 y1 x2 y2
			ans += (pref[x1+1][j+1] - pref[x1+1][i] - pref[0][j+1] + pref[0][i])*(pref[n][j+1] - pref[n][i] - pref[x2][j+1] + pref[x2][i]);
		}
	}
	cout << ans << '\n'; 
}
