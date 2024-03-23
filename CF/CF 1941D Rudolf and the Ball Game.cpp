#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n, m, x; cin >> n >> m >> x;
	stack<int> s;
	s.push(x-1);
	while (m--) {
		int c;
		char type;
		cin >> c >> type;
		set<int> addlater;
		while (!s.empty()) {
			int cur = s.top();
			s.pop();
			if (type != '0') addlater.insert((cur+n-c)%n);
			if (type != '1') addlater.insert((cur+c)%n);
		}
		for (auto x : addlater) {
			s.push(x);
		}
	}
	set<int> ans;
	while (!s.empty()){
		int cur = s.top();
		s.pop();
		ans.insert(cur);
	}
	cout << ans.size() << '\n';
	for (auto x : ans) cout << x+1 << ' ';
	cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}