#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n, k;
    cin >> n >> k;
    map<char, int> lower, upper;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (islower(c)) {
            ++lower[c];
        } else {
            ++upper[c];
        }
    }

    int pairs = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        char C = toupper(c);
        int common = min(lower[c], upper[C]);
        pairs += common;
        lower[c] -= common;
        upper[C] -= common;
    }

    int extra = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        char C = toupper(c);
        int rem = lower[c] + upper[C];
        int operations_needed = rem / 2;
        int to_use = min(operations_needed, k);
        extra += to_use;
        k -= to_use;
    }

    cout << pairs + extra << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
