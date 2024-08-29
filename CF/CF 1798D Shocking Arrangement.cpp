#include <algorithm>
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


void solve() {
    int n; cin >> n;
	multiset<int> pos, neg;
    F0R(i, n){
        int x; cin >> x;
        if (x>=0) pos.insert(x);
        else neg.insert(-x);
    }
    if (n==1){
        cout << "No\n";return;
    }

    int lmao = *pos.rbegin()+(neg.empty() ? 0: *neg.rbegin());
    int sum=0;
    vi ans;
    while(!neg.empty()){
        auto best = neg.upper_bound(lmao+sum);
        //if (best == neg.begin()){
            //cout << "No\n";
            //return;
        //}
        if (best != neg.begin()) --best;

        if (abs(sum-*best) >= lmao){
            if (pos.empty()){
                cout << "No\n";
                return;
            }
            auto pbest = pos.upper_bound(lmao-sum);
            if (pbest != pos.begin()) --pbest;
            ans.push_back(*pbest);
            sum += *pbest;
            pos.erase(pbest);
        }else{
            ans.push_back(-*best);
            sum -= *best;
            neg.erase(best);
        }
        if (sum >= lmao ){cout << "No\n"; return;}
    }
    int psum=0;
    for(auto x: pos) psum += x;
    if (psum >=lmao) {cout << "No\n"; return;}
    cout << "Yes\n";
    for(auto x: ans) cout << x << ' ';
    for(auto x: pos) cout << x << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
