#include <bits/stdc++.h>
using namespace std;

int get_h(vector<int> arr){
	int h = arr.size();
	while (h > 0 && arr[h-1] < h) h--;
	return h;
}

int main() {
	int n, l; cin >> n >> l;
	vector<int> p(n);
	for (int i = 0; i < n; i++) cin >>p[i];
	sort(p.begin(), p.end(), greater<int>());

	int ans = get_h(p);
	if (ans != n) {
		for (int i = ans; i >= 0 && i > ans-l; i--) p[i]++;
	}

	sort(p.begin(), p.end(), greater<int>());

	cout << get_h(p) << '\n';
}
