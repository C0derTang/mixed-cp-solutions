#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n, k;
	cin >> n >> k;
	if (k >= n-1) {
		cout << "1\n";
	}
	else{
		cout << n << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
