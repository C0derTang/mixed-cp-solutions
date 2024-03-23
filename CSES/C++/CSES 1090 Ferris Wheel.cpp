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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, x; cin >> n >> x;
	int children[n];
	FL(i, 0, n) cin >> children[i];
	sort(children, children+n);

	int l=0, r=n-1, ans=0;
	while (l<=r){
		l += (children[l]+children[r] <= x);
		--r;
		++ans;
	}
	cout << ans;
}
