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

void solve(){
	int n; cin >> n;
    vector<int> a(n);
    map<int, int> count;
    int max_size = 0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        ++count[a[i]];
        max_size = max(max_size, count[a[i]]);
    }

    
    // find the smallest subarray in a with the maximum number of elements
    count.clear();
    map<int, int> first;
    int min_len = n+1;
    int l = 0, r = n+1;
    for(int i=0; i<n; ++i){
        if (!first.count(a[i])){
            first[a[i]] = i;
        }
        ++count[a[i]];
        if (count[a[i]] == max_size && i-first[a[i]]+1 < min_len){
            min_len = i-first[a[i]]+1;
            l = first[a[i]]; r = i;
        }
    }
    cout << l+1 << ' ' << r+1;

    
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t = 1;
	while(t--){
		solve();
	}
}
