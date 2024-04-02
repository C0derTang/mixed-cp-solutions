#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

pii simulate(int idx, int h, vi a) {
    for (; idx < a.size(); idx++) {
        if (h > a[idx]) h += a[idx] / 2;
        else break;
    }

    return { idx, h };
}

void solve(){
	int n, h;
	cin >> n >> h;
	vi a(n);
	FL(i,0,n) cin >> a[i];
	sort(a.begin(), a.end());

	pii result = simulate(0, h, a);

    pii result2 = simulate(result.first, result.second * 2,a);
    pii result3 = simulate(result.first, result.second * 3,a);

    pii result23 = simulate(result2.first, result2.second * 3,a);
    pii result22 = simulate(result2.first, result2.second * 2,a);
    pii result32 = simulate(result3.first, result3.second * 2,a);

    pii result232 = simulate(result23.first, result23.second * 2,a);
    pii result223 = simulate(result22.first, result22.second * 3,a);
    pii result322 = simulate(result32.first, result32.second * 2,a);
	
    cout << max(result232.first, max(result223.first, result322.first)) << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
