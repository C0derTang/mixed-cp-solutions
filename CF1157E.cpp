#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    // fun fun fun
    // since elements are only from 0 to n-1
    // that means there is only 1 most optimal complement for all numbers
    // and less optimal complements go upward
    // bsearch nlogn multiset bash surely
    int n; cin >> n;
    vector<int> a(n);
    multiset<int> b;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i){
        int x; cin >> x;
        b.insert(x);
    }
    for(int i=0; i<n; ++i){
        auto it = b.lower_bound((n-a[i])%n);
        if (it == b.end()){
            cout << (a[i]+*b.begin())%n << ' ';
            b.erase(b.begin());

        }else{
            cout << (a[i]+*it)%n << ' ';
            b.erase(it);
        }
    }
}
