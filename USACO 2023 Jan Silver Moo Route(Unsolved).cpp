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
    
    // i hate these type of problems
    // ok its guaranteed at least 1 valid route thats good
    // because we need to return to 0 that means every number will be even
    // assumption: the route with the minimum number of changes will be a mirror
    // counterexample: 2 4 6. expected should be RRRLRLRLLRLL
    // we have to work from the inside out
    //if multiple consecutive elements have the same value treat them as one
    // yeah ima read and compress input and worry abt impl later
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    vector<pair<int, int>> b;
    int cur = a[0];
    int len=0;
    for(int i=0; i<n; ++i){
        if (a[i] == cur){
            ++len;
        }else{
            b.push_back({len, cur});
            cur = a[i];
            len = 1;
        }
    }
    b.push_back({len, cur});
    //for(auto x: b) cout << x.first << ' ' << x.second << '\n';
    // yea this should just be greedy iteration, we move to the back then go in reverse.
    // i think this should work
    reverse(b.begin(), b.end());
    for(int i=0; i<n; ++i) cout << 'R';
    for(auto x: b){
        for(int i=0; i<(x.second-2)/2; ++i){
            for(int i=0; i<x.first; ++i) cout << 'L';
            for(int i=0; i<x.first; ++i) cout << 'R';
        }
        for(int i=0; i<x.first; ++i) cout << 'L';
    }
}
