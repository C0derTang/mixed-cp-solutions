#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), d(m), f(k);
	FL(i, 0, n) cin >> a[i];
	FL(i, 0, m) cin >> d[i];
	FL(i, 0, k) cin >> f[i];
	sort(d.begin(), d.end());
	sort(f.begin(), f.end());

	int largest = 0, second = 0;
	int gap = 0;
	FL(i, 0, n-1){
		if (a[i+1]-a[i] > largest){
			second = largest;
			largest = a[i+1]-a[i];
			gap = i;
		} else if(a[i+1]-a[i] > second){
			second = a[i+1]-a[i];
		}
	}

	int ans = largest;
	for (auto x: d){
		int l=0, r=k-1;
		while (l<=r){
			int mid = (l+r)/2;
			ans = min(ans, max(a[gap+1] - (f[mid]+x), (f[mid]+x) - a[gap]));
			if (a[gap+1] - (f[mid]+x) > (f[mid]+x) - a[gap]) l = mid+1;
			else r = mid-1;
		}
	}
	cout << max(ans, second) << '\n';

}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
