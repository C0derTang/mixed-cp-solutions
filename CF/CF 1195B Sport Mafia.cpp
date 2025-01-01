#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    //pure observation shit uhhh
    // algebra?
    // (n-x)*(n-x+1)/2 - x = k
    // quadratic lmfao
    ll b = 2*n+3;
    ll c = n*n+n-2*k;
    ll ans1 = (-b + sqrt(b*b-4*c))/2;
    ll ans2 = (-b - sqrt(b*b-4*c))/2;
    cout << -max(ans1, ans2);
}