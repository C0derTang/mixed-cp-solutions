#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	string s;
	cin >> n >> s >> q;
	while (q--) {
		int m;
		char c;
		cin >> m >> c;
		int l = 0, wrong = 0, ans = 0;
		for (int r=0; r<n; ++r) {
			if (s[r] != c) ++wrong;
			while (wrong > m) {
				if (s[l] != c) --wrong;
				++l;
			}
			ans = max(ans, r-l+1);
		}
		cout << ans << '\n';
	}
}
