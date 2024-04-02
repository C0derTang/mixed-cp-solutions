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

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	FL(i, 0, n) cin >> a[i];
	map<int, int> count;
	FL(i, 0, n) ++count[a[i]];

	vi val;
    for (auto x : count) if (x.S >=k) val.PB(x.F);

    if (val.empty()){
        cout << "-1\n";
        return;
    }

	int l = val[0], r = val[0], maxlen = 0, curl = val[0];
	FL(i, 1, val.size()){
		if (val[i] == val[i-1]+1){
			if (val[i] - curl> maxlen){
				l = curl;
				r = val[i];
				maxlen = r-l;
			}
		}else{
			curl = val[i];
		}
	}

	if (maxlen == 0){
		cout << val[0] << ' ' << val[0] << '\n';
	}else{
		cout << l << ' ' << r << '\n';
	}

}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
}
