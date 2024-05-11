#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
	int n, m; 
	cin >> n >> m;
	vector<int> arr(n);
	vector<int> ind(n);
	for(int i=0; i<n; ++i) {
		cin >> arr[i];
		--arr[i];
		ind[arr[i]] = i;
	}

	int ans=1;
	for(int i=1; i<n; ++i){
		ans += ind[i] < ind[i-1];
	}

	while(m--){
		int a, b;
		cin >> a >> b;
		--a; --b;
		int f = arr[a], s = arr[b];
		swap(arr[a], arr[b]);
		if (f-1 >= 0)
		{ans += (ind[f-1] <= ind[f] && ind[f-1] > b);
		ans -= (ind[f-1] > ind[f] && ind[f-1] <= b);}
		if (f+1 < n)
		{ans += (ind[f] <= ind[f+1] && b > ind[f+1]);
		ans -= (ind[f] > ind[f+1] && b <= ind[f+1]);}
		ind[f] = b;

		if (s-1 >=0)
		{ans += (ind[s-1] <= ind[s] && ind[s-1] > a);
		ans -= (ind[s-1] > ind[s] && ind[s-1] <= a);}
		if (s+1 <n)
		{ans += (ind[s] <= ind[s+1] && a > ind[s+1]);
		ans -= (ind[s] > ind[s+1] && a <= ind[s+1]);}
		ind[s] = a;
		
		cout << ans << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	while(t--){
		solve();
	}
}
