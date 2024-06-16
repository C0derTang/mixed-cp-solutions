#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    int n; 
    cin >> n;
    vector<int> a(n), b(n);

	map<int, int> bash;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {cin >> b[i]; ++bash[b[i]];};

	int m; cin >> m;
	vector<int> d(m);
	for (int i=0; i<m; ++i) {
		cin >> d[i];
	}

	int diff = 0;
	map<int, int> lmao;
	for(int i=0; i<n; ++i){
		if (a[i] != b[i]){
			++diff;
			++lmao[b[i]];
		}
		if (diff > m ){
			cout << "NO\n";
			return;
		}
	}


	bool mod = false;
	for(auto x: d){
		if (bash.find(x) != bash.end()){
			if (lmao[x] > 0) --lmao[x];
			mod = false;
		}else{
			mod = true;
		}
	}

	bool check = false;
	for(auto x: lmao){
		if (x.second){
			check = true;
			break;
		}
	}
	cout << (mod || check ? "NO\n" : "YES\n");

    
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t; // = 1;
    while (t--) {
        solve();
    }
}