#include <bits/stdc++.h>

using namespace std;

#define ll long long


bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	int n, m;
	cin >> n >> m;
	string s; cin >> s;
	set<int> ind;
	for(int i=0; i<m; ++i){
		int x; cin >> x;
		ind.insert(x);
	}
	vector<char> c(m);
	for(int i=0; i<m; ++i) cin >> c[i];
	sort(c.begin(), c.end());

	int ci=0;
	for(auto i: ind){
		s[i-1] = c[ci];
		++ci;
	}
	cout << s << '\n';

}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
