#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int a, b, k; cin >> a >> b >> k;
	vector<int> boys(a), girls(b);
	vector <pii> rizz(k);
	for (int i=0; i<k; ++i) {
		cin >> rizz[i].first;
		--rizz[i].first;
		++boys[rizz[i].first];
	}
	for (int i=0; i<k; ++i) {
		cin >> rizz[i].second;
		--rizz[i].second;
		++girls[rizz[i].second];
	}

	ll ans = 0;
	for (int i=0; i<k; ++i) {
		ans += k - boys[rizz[i].first] - girls[rizz[i].second] + 1;
	}
	cout << ans / 2<< '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
