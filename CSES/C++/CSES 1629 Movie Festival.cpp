#include <bits/stdc++.h>
using namespace std;


#define int long long
#define pii pair<int, int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	pii movies[n];
	FL(i, 0, n){
		cin >> movies[i].F >> movies[i].S;
	}
	sort(movies, movies+n, cbs);

	int ans = 0, free = 0;
	for (auto x: movies){
		if (free <= x.F){
			++ans;
			free = x.S;
		}
	}
	cout << ans;
}
