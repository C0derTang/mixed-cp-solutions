#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i=0; i<m; ++i){
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> parent(n, -1);

	for(int i=0; i<n; ++i){
		if(parent[i] != -1) continue;
		stack<int> st;
		st.push(i);
		while(!st.empty()){
			int cur=st.top();
			st.pop();
			for(auto x: adj[cur]){
				if (x == parent[cur]) continue;
				if(parent[x] == -1){
					parent[x] = cur;
					st.push(x);
				}else{
					vector<int> ret = {x+1, cur+1};
					
					while(cur != parent[x]){
						cur = parent[cur];
						ret.push_back(cur+1);
					}
					
					cout << ret.size()+1 << '\n';
					for(auto y: ret) cout << y << ' ';
					cout << x+1;
					return 0;
				}
			}
		}
	}
	
	cout << "IMPOSSIBLE";
}