#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n, m, k, d;
	cin >> n >> m >> k >> d;
	int costs[n];
	FL(i, 0, n){
		int a[m]; FL(j, 0, m){
			cin >> a[j];
			++a[j];
		}

		vector<int> dp(m, LLONG_MAX);
		dp[0] = a[0];
		deque<int> dq;
		dq.PB(0);
		FL(j, 1, m){
			while (!dq.empty() && dq.front() < j-d-1) dq.pop_front();
			dp[j] = dp[dq.front()] + a[j];
			while (!dq.empty() && dp[j] <= dp[dq.back()]) dq.pop_back();
			dq.PB(j);
		}
		costs[i] = dp[m-1];
	}

	int sum = 0;
	FL(i, 0, k) sum += costs[i];

	int minsum = sum;
	FL(i, k, n){
		sum += costs[i] - costs[i-k];
		minsum = min(minsum, sum);
	}
	cout << minsum << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
