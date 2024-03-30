#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

vi binums;

bool isbin(int num) {
    while (num > 0) {
        if (num % 10 != 0 && num % 10 != 1) return false;
        num /= 10;
    }
    return true;
}


void solve(){
	int n; cin >> n;

	auto p = binums.rbegin();
	while (p != binums.rend() && n > 1){
		while (n % *p == 0) n /= *p;
		++p;
	}
	cout << (n==1 ? "YES" : "NO") << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	FL(i, 2, 100001){
		if (isbin(i)){
			binums.PB(i);
		}
	}

	int t; cin >> t;
	while(t--){
		solve();
	}
}
