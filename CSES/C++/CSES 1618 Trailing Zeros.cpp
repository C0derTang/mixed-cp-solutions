#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int recurse(int n){
	if (n==0) return 0;
	return n/5 + recurse (n/5);
}
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	cout << recurse(n);
