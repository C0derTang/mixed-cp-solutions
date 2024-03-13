#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

bool compare(pii a, pii b) {
	if (a.second == b.second){
		return a.first > b.first;
	}
    return a.second < b.second;
}

int main() {
	int n;
	cin >> n;
	vector<pii> peaks(n);
	for (int i=0; i<n; ++i){
		int x, y;
		cin >> x >> y;
		peaks[i].first = x-y;
		peaks[i].second = x+y;
	}
	sort(peaks.begin(), peaks.end(), compare);

	int ans = 1;
	for (int i=n-1; i>0; --i){
		if (peaks[i].first <= peaks[i-1].first){
			peaks[i-1].first = peaks[i].first;
			peaks[i-1].second = peaks[i].second;
		}else{
			++ans;
		}
		peaks.pop_back();
	}
	cout << ans;
}
