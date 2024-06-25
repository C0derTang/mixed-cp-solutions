#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long

vector<int> pre(1000001);

void precomp(){
	pre[1]=1;
	pre[2]=5;
	pre[3]=10;
	for(int i=4; i<=1000000; ++i){
		int row=1;
		while(row*(row+1) / 2 <i) ++row;
		int pos = i - (row*(row-1)/2);
		pre[i] = i*i;
		if (row-1 >= 1 && (row-2)*(row-1)/2+pos <= (row-1)*row/2){
			pre[i] += pre[(row-2)*(row-1)/2 + pos];
		}
		if (row-1 >= 1 && (row-2)*(row-1)/2+pos-1 > (row-2)*(row-1)/2){
			pre[i] += pre[(row-2)*(row-1)/2 + pos-1];
		}
		if (row-2 >= 1 && (row-3)*(row-2)/2+pos-1 <= (row-2)*(row-1)/2 && (row-3)*(row-2)/2+pos-1 > (row-3)*(row-2)/2){
			pre[i] -= pre[(row-3)*(row-2)/2 + pos-1];
		}
	}
}


void solve(){
	int n; cin >> n;
	cout << pre[n] << '\n';
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	precomp();
	while(t--){
		solve();
	}
}
