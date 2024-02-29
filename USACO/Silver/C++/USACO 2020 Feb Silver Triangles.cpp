
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

const int MAXN = 1e5;
const int MOD = 1e9 + 7;
const int MAXC = 1e4;

struct Fence{
	int x, y;
	ll heightsum = 0;
	ll basesum = 0;
};

Fence fences[MAXN];
vector<pii> xcoords[2*MAXC+1];
vector<pii> ycoords[2*MAXC+1];

int main() {
	int n;
	cin >> n;

	for (int i=0; i<n; ++i){
		cin >> fences[i].x >> fences[i].y;
		xcoords[fences[i].x + MAXC].push_back({fences[i].y, i});
		ycoords[fences[i].y + MAXC].push_back({fences[i].x, i});
	}

	for (int i=0; i < 2*MAXC+1; ++i){
		if (xcoords[i].size() <= 0) {
			continue;
		}
		sort(xcoords[i].begin(), xcoords[i].end());

		for (int j=1; j<xcoords[i].size(); ++j) {
			fences[xcoords[i][0].second].heightsum += xcoords[i][j].first - xcoords[i][0].first;
		}
		ll cur = fences[xcoords[i][0].second].heightsum ;
		for (int j=1; j<xcoords[i].size(); ++j) {
			cur += (2*j - xcoords[i].size())*(xcoords[i][j].first - xcoords[i][j-1].first);
			fences[xcoords[i][j].second].heightsum = cur;
		}
	}

	for (int i=0; i < 2*MAXC+1; ++i){
		if (ycoords[i].size() <= 0) {
			continue;
		}
		sort(ycoords[i].begin(), ycoords[i].end());

		for (int j=1; j<ycoords[i].size(); ++j) {
			fences[ycoords[i][0].second].basesum += ycoords[i][j].first - ycoords[i][0].first;
		}
		ll cur = fences[ycoords[i][0].second].basesum ;
		for (int j=1; j<ycoords[i].size(); ++j) {
			cur += (2*j - ycoords[i].size())*(ycoords[i][j].first - ycoords[i][j-1].first);
			fences[ycoords[i][j].second].basesum = cur;
		}
	}


	ll ans = 0;
	for (int i=0; i<n; ++i) {
		ans += fences[i].basesum * fences[i].heightsum % MOD;
		ans %= MOD;
	}
	cout << ans;

}
