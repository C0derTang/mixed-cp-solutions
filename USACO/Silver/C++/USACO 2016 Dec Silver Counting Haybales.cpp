#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long

// so theres a binary search solution but i was lowkey lazy and cheesed

int main() {
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	ordered_set<int> bash;
	for(int i=0; i<n; ++i){
		int x; cin >> x;
		bash.insert(x);
	}

	while(q--){
		int a, b;
		cin >> a >> b;

		int ans = bash.order_of_key(b) - bash.order_of_key(a);
		ans += bash.find(b) != bash.end();
		cout <<  ans << '\n';

	}
	
}
