#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve(){
	int n; cin >> n;
	char a[n];
	int lcount = 0;
	int rcount = 0;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		if (a[i] == '0'){
			++lcount;
		}else{
			++rcount;
		}
	}

	if (lcount == n){
		cout << n << '\n';
		return;
	}
	if (rcount == n){
		cout << "0\n";
		return;
	}
	int curl = 0;
	int curr = 0;
	double min_cost = (double)n/2.0;
	int lmao = -1;
	for (int i=0; i<n; ++i) {
		if (a[i] == '0'){
			++curl;
		}else{
			++curr;
		}
		if (curl >= ceil((double)(i+1)/2.0) && (rcount-curr) >= ceil((double)(n-i-1)/2.0)) {
			if (fabs(double(n)/2.0-double(i+1)) < min_cost) {
				min_cost = fabs(double(n)/2.0-double(i+1));
				lmao = i+1;
			}
		}
	}
	if (lmao == -1){
		if (lcount > rcount){
			cout << n << '\n';
		}else{
			cout << "0\n";
		}
	}else{
		cout << lmao << '\n';
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
