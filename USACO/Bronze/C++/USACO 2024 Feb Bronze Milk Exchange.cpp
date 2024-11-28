#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
	int n, m;
	cin >> n >> m;
	string s; cin >> s;
	vector<int> buckets(n);
	for(int i=0; i<n; ++i) cin >> buckets[i];

	int ans = accumulate(buckets.begin(), buckets.end(), 0LL);

	for(int i=0; i<n-1; ++i){
		if (s[i] == 'R' && s[i+1] == 'L'){
			int cur = (i>0 ? i-1 : n-1);
			int count = 0;
			while(s[cur] == 'R'){
				count += buckets[cur];
				--cur;
				if (cur < 0) cur = n-1;
			}
			ans -= min(count, m);

			cur = (i+2 < n ? i+2 : 0);
			count = 0;
			while(s[cur] == 'L'){
				count += buckets[cur];
				++cur;
				if (cur >= n) cur = 0;
			}
			ans -= min(count, m);

		}
	}

	if (s[0] == 'L' && s[n-1] == 'R'){
		int cur = 1;
		int count = 0;
		while(s[cur] == 'L'){
			count += buckets[cur];
			++cur;
		}
		ans -= min(count, m);
		cur = n-2;
		count = 0;
		while(s[cur] == 'R'){
			count += buckets[cur];
			--cur;
		}
		ans -= min(count, m);
	}


	cout << ans;
}
