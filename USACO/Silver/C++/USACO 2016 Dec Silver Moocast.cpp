#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n; cin >> n;
	vector<pair<pair<int, int>, int>> cows(n);
	for(int i=0; i<n; ++i) cin >> cows[i].first.first >> cows[i].first.second >> cows[i].second;
	
	vector<vector<int>> adj(n);
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if ((cows[i].first.first - cows[j].first.first)*(cows[i].first.first - cows[j].first.first) + (cows[i].first.second - cows[j].first.second)*(cows[i].first.second - cows[j].first.second) <= cows[i].second*cows[i].second) adj[i].push_back(j);
		}
	}
	
    int ans=0;
    for(int i=0; i<n; ++i){
        set<int> seen;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if (seen.count(cur)) continue;
            seen.insert(cur);
            for(auto x: adj[cur]) {
                if (seen.count(x)) continue;
                q.push(x);
            }
        }
        ans = max(ans, (int)seen.size());
    }
    cout << ans;
}
