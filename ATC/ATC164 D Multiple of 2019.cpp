#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    string s;
    cin >> s;
    int n = s.size();
    // keep running suff sum, % 2019.
    // for each sum, add s[i]*10*length of number.
    // keep track of each remainder
    // (a*b)%x = (a%x)*(b%x)
    vector<int> rem(2019);
    int sum = 0;
    int pow = 1;
    ++rem[0];
    for(int i=n-1; i>-1; --i){
        sum += (s[i]-'0')*pow;
        sum %= 2019;
        pow *= 10;
        pow %= 2019;
        ++rem[sum];
    }
    int ans=0;
    for(auto x: rem) ans += x*(x-1)/2;
    cout << ans;
}
