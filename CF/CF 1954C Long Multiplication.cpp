#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
	string a, b;
	cin >> a >> b;
	int n = a.length();

	int comp = 0;
	while (comp < n-1 && a[comp] == b[comp]) ++comp;
	if (b[comp] > a[comp]) swap(a[comp], b[comp]);
	for(int i=comp+1; i<n; ++i){
		if (a[i] > b[i]) swap(a[i], b[i]);
	}

	cout << a << '\n' << b << '\n';


}

//first DIFFERENT digit make sure the larger one is on top
// every oteher digit make sure the
signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}