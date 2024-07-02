#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n; cin >> n;
	int ans=0;
	while(n !=0){
		string s = to_string(n);
		int maxd = 0;
		for(auto c: s){
			maxd = max(maxd, c-'0');
		}
		n -= maxd;
		++ans;
	}
	cout << ans;
}
