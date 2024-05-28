#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	if ((a+b+c) % 2){
		cout << "-1\n";
		return;
	}

	cout << min(a+b, (a+b+c)/2) << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
