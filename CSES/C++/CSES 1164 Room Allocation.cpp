#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

struct compare {
    bool operator()(const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b) {
        if (a.first != b.first) return a.first > b.first; 
        return a.second.first < b.second.first; 
    }
};


signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int n; cin >> n;
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, compare> pq;
    set<int> free, taken;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        pq.push({a, {1, i+1}});
        pq.push({b, {-1, i+1}});
        free.insert(i+1);
    }

    int k=0;
    vector<int> ans(n);
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(cur.second.first == 1){
            ans[cur.second.second-1] = *free.begin();
            taken.insert(*free.begin());
            free.erase(free.begin());
        }else{
            taken.erase(ans[cur.second.second-1]);
            free.insert(ans[cur.second.second-1]);
        }
        k = max(k, (int)taken.size());
    }

    cout << k << '\n';
    for(auto x: ans) cout << x << ' ';
}
