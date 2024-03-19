#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n, w;
	cin >> n >> w;
	multiset<int> widths;
	for (int i=0; i<n; ++i) {
		int x; cin >> x;
		widths.insert(x);
	}

	int layers = 1;
	int wremaining = w;
	while (!widths.empty()){
		auto it = widths.upper_bound(wremaining);
		if (it == widths.begin()){
			++layers;
			wremaining = w;
		}else{
			--it;
			wremaining -= *it;
			widths.erase(it);
		}
	}

	cout << layers << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
