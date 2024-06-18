#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);

	vector<int> pattern = {1, 2, 4, 7, 8, 11, 13, 14};

	int n; cin >> n;

	int blocks = (n-1)/8;
	int pos = (n-1)%8;
	
	cout << blocks * 15 + pattern[pos];

}
