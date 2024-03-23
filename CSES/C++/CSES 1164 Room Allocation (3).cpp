// messes up tc3

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(vector<int> a, vector<int> b) {
    return a[0] > b[0];
}

struct VectorCompare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
		return a[0] >= b[0];
    }
};


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	priority_queue<vector<int>, vector<vector<int>>, VectorCompare> pq;
	set<int> available, taken;
	FL(i, 0, n){
		int a, b; cin >> a >> b;
		vector<int> cow = {a, b-a+1, i};
		pq.push(cow);
		available.insert(i+1);
	}

	int ans[n];
	while (!pq.empty()) {
		vector<int> cur = pq.top();
		pq.pop();
		if (cur[1] != -1){
			ans[cur[2]] = *available.begin();
			available.erase(available.begin());
			vector<int> newv = {cur[0]+cur[1], -1, cur[2]};
			pq.push(newv);
		}else{
			available.insert(ans[cur[2]]);
		}
	}
	cout << *max_element(ans, ans+n) << '\n';
	FL(i, 0, n) cout << ans[i] << ' ';
}
