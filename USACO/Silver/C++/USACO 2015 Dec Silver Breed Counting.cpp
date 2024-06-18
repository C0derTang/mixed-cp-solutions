#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	vector<int> h(n+1), g(n+1), j(n+1);
	for(int i=0; i<n; ++i){
		int x; cin >> x;
		h[i+1] = h[i] + (x == 1);
		g[i+1] = g[i] + (x == 2);
		j[i+1] = j[i] + (x == 3);
	}

	while(q--){
		int a, b;
		cin >> a >> b;
		--a;
		cout << h[b] - h[a] << ' ' << g[b]-g[a] << ' ' << j[b]-j[a] << '\n';
	}
}
