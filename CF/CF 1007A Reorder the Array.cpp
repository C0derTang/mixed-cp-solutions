#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	multiset<int> bash;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		bash.insert(a[i]);
	}
	sort(a.begin(), a.end());

	int ans = 0;
	for(int i=0; i<n; ++i){
		if (bash.upper_bound(a[i]) != bash.end()){
			++ans;
			bash.erase(bash.upper_bound(a[i]));
		}
	}
	cout << ans;
}

//lowkey overthought ngl just a n - max repetitions works too