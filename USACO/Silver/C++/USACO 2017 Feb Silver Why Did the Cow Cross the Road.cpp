#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);

	int c, n;
	cin >> c >> n;
	vector<int> chikun(c);
	for(int i=0; i<c; ++i) cin >> chikun[i];
	vector<pair<int, int>> cows(n);
	for(int i=0; i<n; ++i) cin >> cows[i].first >> cows[i].second;

	sort(chikun.begin(), chikun.end());
	sort(cows.begin(), cows.end(), cbs);

	int i = 0, j = 0, ans = 0;
	while(i < c && j < n){
		if(chikun[i] > cows[j].second) ++j;
		else if (chikun[i] < cows[j].first) ++i;
		else{
			++ans; ++i; ++j;
		}
	}

	cout << ans;
}
