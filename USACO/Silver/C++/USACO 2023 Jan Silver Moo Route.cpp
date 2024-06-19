#include <bits/stdc++.h>

using namespace std;

#define ll long long

//so uh literally just simulate it ig
//lowkey weird impl. think its relatively clean tho

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];
	
	// initial move always to the right
	cout << 'R';
	
	int i = 0, dir = 1;
	while(true){
		--a[i];
		if (i==0 && a[i] == 0) break;

		if (i+dir > n-1 || i+dir < 0 || a[i+dir] < a[i]) dir *= -1;
		else i += dir;
		
		cout << (dir == 1 ? 'R' : 'L');
	}
}
