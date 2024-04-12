#include <bits/stdc++.h>
using namespace std;

set<string> seen;

void permute(string cur, int l, int r){
	if (l == r){
		seen.insert(cur);
	}else{
		for (int i=l; i<r; ++i) {
			swap(cur[l], cur[i]);
			permute(cur, l+1, r);
			swap(cur[l], cur[i]);
		}
	}

}

int main() {
	string n;
	cin >> n;
	permute(n, 0, n.size());

	cout << seen.size() << '\n';
	for (auto x : seen) {
		cout << x << '\n';
	}
}
