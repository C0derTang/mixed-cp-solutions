#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n; cin >> n;
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    --ax; --ay; --bx; --by; --cx; --cy;
    vector<vector<bool>> check(n, vector<bool>(n));
    vector<pair<int, int>> mod = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for(auto move : mod){
        int dx = move.first;
        int dy = move.second;
        int tx = ax, ty = ay;
        while(tx > -1 && tx < n && ty > -1 && ty < n){
            check[tx][ty] = true;
            tx += dx;
            ty += dy;
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> seen(n, vector<bool>(n));
    q.push({bx, by});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if (cur.first == cx && cur.second == cy){
            cout << "YES";
            return 0;
        }
        seen[cur.first][cur.second] = true;
        for(auto move: mod){
            int tx = cur.first+move.first;
            int ty = cur.second+move.second;
            if (tx > -1 && tx < n && ty > -1 && ty < n && !seen[tx][ty] && !check[tx][ty]) {
                seen[tx][ty] = true;
                q.push({tx, ty});
            }
        }
    }

    cout << "NO";
}