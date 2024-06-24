#include <bits/stdc++.h>

using namespace std;

#define ll long long


bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	cout << min(abs(a-b) + abs(a-c), min(abs(b-a)+abs(b-c), abs(c-a) +abs(c-b))) << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}