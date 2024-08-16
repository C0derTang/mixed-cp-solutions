#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<pair<T, long long>, null_type, less<pair<T, long long>>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>

#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define F0R(i, a) for(int i=0; i<a; ++i)
#define ROF(i, a, b) for(int i=b; i>a-1; --i)
#define R0F(i, a) for(int i=a; i>-1; --i)
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

const int tx[4] = {1, -1, 0, 0};
const int ty[4] = {0, 0, 1, -1};
const string lame = "DURL";

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    F0R(i, n) cin >> grid[i];

    pii apos = {-1, -1};
    F0R(i, n) {
        F0R(j, m) {
            if (grid[i][j] == 'A') {
                apos.first = i;
                apos.second = j;
                break;
            }
        }
    }

    vector<vector<bool>> seen(n, vector<bool>(m));
    vector<vector<char>> parent_move(n, vector<char>(m));
    vector<vector<pii>> parent_pos(n, vector<pii>(m, {-1, -1}));

    queue<pii> q;
    q.push(apos);
    seen[apos.first][apos.second] = true;

    while (!q.empty()) {
        pii cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();

        if (grid[x][y] == 'B') {
            cout << "YES\n";
            vector<char> path;
            while (grid[x][y] != 'A') {
                path.push_back(parent_move[x][y]);
                pii p = parent_pos[x][y];
                x = p.first;
                y = p.second;
            }
            reverse(path.begin(), path.end());
            cout << path.size() << '\n';
            for (char c : path) cout << c;
            return;
        }

        F0R(i, 4) {
            int nx = x + tx[i];
            int ny = y + ty[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || seen[nx][ny] || grid[nx][ny] == '#') continue;
            seen[nx][ny] = true;
            parent_move[nx][ny] = lame[i];
            parent_pos[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }
    cout << "NO\n";
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t=1;
    while(t--){
        solve();
    }
}
