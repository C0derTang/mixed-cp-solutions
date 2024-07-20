#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <numeric>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))


void solve(){
	int n;
	cin >> n;
	vi a(n);
	F0R(i, n) cin >> a[i];

	int tot = accumulate(a.begin(), a.end(), 0, bit_xor<int>());

	if(tot==0){
		cout << "1\n1 " << n << '\n';
	}else if (n%2){
		cout << "4\n1 " << n << "\n1 " << n-1 << '\n' << n-1 << ' ' << n << '\n' << n-1 << ' ' << n << '\n';
	}else{
		cout << "2\n1 " << n << "\n1 " << n << '\n';
	}
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
