#include <bits/stdc++.h>
using namespace std;

int main() {
	// input bottleneck is crazy
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, n;
	cin >> x >> n;

	set<int> lights;
	lights.insert(0);
	lights.insert(x);

	multiset<int> gaps;
	gaps.insert(x);

	while (n--) {
		int light;
		cin >> light;
		auto it1 = lights.upper_bound(light);
		auto it2 = it1;
		--it2;
		
		gaps.erase(gaps.find(*it1-*it2));
		lights.insert(light);
		gaps.insert(*it1-light);
		gaps.insert(light-*it2);

		cout << *gaps.rbegin() << ' ';
	}

}
