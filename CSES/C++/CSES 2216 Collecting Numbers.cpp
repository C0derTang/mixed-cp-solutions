#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; ++i) cin >> a[i];
 
	// iterate thru the array
	// keep unordered_set of integers
	// if a[i]-1 is in set, then replace the element
	// else ++ans
 
	int ans=0;
	unordered_set<int> nxt;
	for(int i=0; i<n; ++i){
		if (nxt.find(a[i]-1) == nxt.end()){
			++ans;
		}
		nxt.insert(a[i]);
	}
	cout << ans;
}