#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n, m, k;
	cin >> n >> m >> k;
    if (n>m) swap(n,m);
	if (m > k){
		cout << "-1\n";
		return;
	}

    if (m%2 != k%2){
        --m;--k;
    }
    if (n>m) swap(n,m);
    if(m%2 != n%2){
        --m;--k;
    }
    cout << (max(n, m) + (k-max(n, m))) << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int q; cin >> q;
    while(q--){
        solve();
    }
}
