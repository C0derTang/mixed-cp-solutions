#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;
	cin >> n >> s;
	int a[n];
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	sort(a, a+n);
	ll ans = 0;
	if (a[n/2] > s){
		for (int i=0; i<n/2+1; ++i) {
			if (a[i] > s){
				ans += a[i]-s;
			}
		}
	}else if (a[n/2] < s){
		for (int i=n/2; i<n; ++i) {
			if (a[i] < s){
				ans += s-a[i];
			}
		}
	}
	
	cout << ans;
}
