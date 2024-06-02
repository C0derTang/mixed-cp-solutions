#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, g, n;
	cin >> b >> g >> n;

	//too lazy to math it, will just simulate
	int ans = 0;
	for(int i=0; i<n+1; ++i){
		if (n-i > g || i > b) continue;
		++ans;
	}
	cout << ans;
}
