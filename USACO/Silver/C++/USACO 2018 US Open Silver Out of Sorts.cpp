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
	// read in data
	int n; cin >> n;
	vi a(n);
	FL(i, 0, n) cin >> a[i];

	//number of moos is the most out of place element
	vi sorted = a;
	sort(sorted.begin(), sorted.end());
	map<int, int> pos;
	FL(i, 0, n) pos[sorted[i]] = i;

	int ans = 1;
	FL(i, 0, n){
		ans = max(ans, max((int)0, i-pos[a[i]]+1));
	}
	cout << ans;
	/* brute force method
	int ans=0;
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		++ans;
		FL(i, 0, n-1){
			if (a[i+1] < a[i]) {
				swap(a[i], a[i+1]);
				sorted = false;
			}
		}
	}
	cout << ans;
	*/

}

signed main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
