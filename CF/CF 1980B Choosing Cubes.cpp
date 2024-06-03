// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, f, k;
	cin >> n >> f >> k;
	vector<int> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	int val = a[f-1];

	sort(a.begin(), a.end(), greater<>());

	int dumb = 0;
	for(int i=0; i<k; ++i){
		if (a[i] == val){
			++dumb; break;
		}
	}
	if (k < n && a[k] == val && dumb == 1){
		++dumb;
	}
	if (dumb == 0) cout << "NO\n";
	else if(dumb == 1) cout << "YES\n";
	else cout << "MAYBE\n";


}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
