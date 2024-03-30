#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define loop(i, j, n, k) for(int i = j; i <= n; i += k)
#define fast ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

using ll = long long;
using pii = pair<int, int>;
using pss = pair<string, string>;
using vi = vector<int>;

vector<vi> dir{{1, 0, -1, 0}, {0, 1, 0, -1}};

void bfs(int x, int y, vector<vector<bool>> &visited, int NumRows, int NumCols) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int cur_x = cur.fi, cur_y = cur.se;

        for (int i = 0; i < 4; i++) {
            int nxt_x = cur_x + dir[0][i];
            int nxt_y = cur_y + dir[1][i];

            if (nxt_x >= 1 && nxt_x <= NumRows && nxt_y >= 1 && nxt_y <= NumCols && !visited[nxt_x][nxt_y]) {
                q.push({nxt_x, nxt_y});
                visited[nxt_x][nxt_y] = true;
            }
        }
    }
}

int main() {
    fast;
    int NumRows, NumCols;
    cin >> NumRows >> NumCols;
    vector<vector<bool>> visited(NumRows + 2, vector<bool>(NumCols + 2, false));

    loop(i, 1, NumRows, 1) {
        loop(j, 1, NumCols, 1) {
            char c;
            cin >> c;
            visited[i][j] = (c == '#');
        }
    }

    int ans = 0;

    loop(i, 1, NumRows, 1) {
        loop(j, 1, NumCols, 1) {
            if (!visited[i][j]) {
                bfs(i, j, visited, NumRows, NumCols);
                ans++;
            }
        }
    }

    cout << ans;
}
