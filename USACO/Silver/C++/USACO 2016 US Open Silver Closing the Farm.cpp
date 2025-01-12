#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

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

    

    vector<bool> closed(n);
    for(int k=0; k<n; ++k){
        bool single = false;
        vector<bool> seen(n);
        for(int i=0; i<n; ++i){
            if (seen[i] || closed[i]) continue;
            if (single){
                single = false;
                break;
            }else{
                single = true;
            }
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                seen[q.front()] = true;
                for(auto x: adj[q.front()]){
                    if (!seen[x] && !closed[x]) q.push(x);
                }
                q.pop();
            }
        }
        cout << (single ? "YES\n":"NO\n");
        int x; cin >> x;
        --x;
        closed[x] = true;
    }
	
}
