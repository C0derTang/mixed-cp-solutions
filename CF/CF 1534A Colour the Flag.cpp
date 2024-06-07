#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

vector<int> dx = {0,0,1,-1};
vector<int> dy = {-1,1,0,0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> grid[i][j];
    
    bool val1 = true;
    vector<vector<char>> p1(n, vector<char>(m, '.'));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(i%2) p1[i][j] = (j%2 ? 'W' : 'R');
            else p1[i][j] = (j%2 ? 'R' : 'W');
            if (p1[i][j] != grid[i][j] && grid[i][j] != '.'){
                val1 = false;
                break;
            }
        }
        if (!val1) break;
    }
    if (val1){
        cout << "YES\n";
        for (int i=0; i<n; ++i){
            for (auto c: p1[i]) cout << c;
            cout << '\n';
        }
        return;
    }

    bool val2 = true;
    vector<vector<char>> p2(n, vector<char>(m, '.'));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(i%2) p2[i][j] = (j%2 ? 'R' : 'W');
            else p2[i][j] = (j%2 ? 'W' : 'R');
            if (p2[i][j] != grid[i][j] && grid[i][j] != '.'){
                val2 = false;
                break;
            }
        }
        if (!val2) break;
    }
    if (val2){
        cout << "YES\n";
        for (int i=0; i<n; ++i){
            for (auto c: p2[i]) cout << c;
            cout << '\n';
        }
        return;
    }
    cout << "NO\n";
   
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);
	int t; cin >> t; // = 1;
	while(t--){
		solve();
	}
}
