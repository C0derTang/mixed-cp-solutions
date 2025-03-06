#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve(){
    int n; cin >> n;
    vector<set<int>> fow(n);
    //vector<set<int>> rev(n);

    for(int i=0; i<n-1; ++i){
        int x; cin >> x; --x;
        fow[x].insert(i+1);
        //rev[i+1].insert(x);
    }
    int level = 0;
    vector<set<int>> bash(n);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int temp = q.size();
        while(temp--){
            bash[level].insert(q.front());
            for(auto x: fow[q.front()]){
                q.push(x);
            }
            q.pop();
        }
        ++level;
    }
    vector<int> ans(n, 1);
    int prev = bash[n-1].size();
    for(int i=n-2; i>-1; --i){
        int cur = 0;
        for(auto x: bash[i]){
            ans[x] += prev;
            if (x != 0) for(auto y: fow[x]) ans[x] = (ans[x] - ans[y] + 998244353) % 998244353;
            ans[x] %= 998244353;
            cur += ans[x];
            cur %= 998244353;
        }
        prev = cur;
    }
    //for(auto x: ans) cout << x << ' ';
    //cout << '\n';
    cout << ans[0] << '\n';
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}