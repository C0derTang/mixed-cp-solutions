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
	int n, x, y;
	cin >> n >> x >> y;
	vi vertices(x);
	FL(i, 0, x) cin >> vertices[i];
	sort(vertices.begin(), vertices.end());

	int ans = x-2;
	FL(i, 0, x-1) if (vertices[i]+2 == vertices[i+1]) ++ans;
	if ((vertices[x-1]+2)%n == vertices[0]) ++ ans;
	cout << ans << '\n';

}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
