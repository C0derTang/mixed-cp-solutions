#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

int n;
ll ans = 0;
vector<pair<int, int>> cows;

pii compare(pii a, int b){
	return {min(a.first, b), max(a.second, b)};
}

ll calc(){
	sort(cows.begin(), cows.end());

	vector<pii> pref(n), suff(n);

	pref[0] = {cows[0].second, cows[0].second};
	for (int i = 1; i<n; ++i) {
		pref[i] = compare(pref[i-1], cows[i].second);
	}

	suff[n-1] = {cows[n-1].second, cows[n-1].second};
	for (int i=n-2; i>=0; --i){
		suff[i] = compare(suff[i+1], cows[i].second);
	}

	ll area = (ll)(cows.back().first - cows.front().first) * (pref.back().second - pref.back().first);

	ll min_a = 1000000000000000000;
	for (int i=0; i<n-1; ++i) {
		if (cows[i].first != cows[i+1].first){
		ll fence1 = (ll)(cows[i].first - cows[0].first)*(pref[i].second - pref[i].first);
		ll fence2 = (ll)(cows.back().first - cows[i+1].first)*(suff[i+1].second - suff[i+1].first);
		min_a = min(min_a, fence1+fence2);
		}
	}

	return area - min_a;
}

int main() {
	cin >> n;
	cows.resize(n);
	for (pii &cow : cows){
		cin >> cow.first >> cow.second;
	}
	ans = calc();
	for (pii &cow : cows) {
		swap(cow.first, cow.second);
	}
	ans = max(ans, calc());

	cout << ans;
}
