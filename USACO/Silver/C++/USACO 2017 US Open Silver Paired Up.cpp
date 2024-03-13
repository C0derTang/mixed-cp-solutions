#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    map<int, int> cows;
    for (int i=0; i<n; ++i){
        int v, k;
        cin >> v >> k;
        cows[k] = v;
    }

    int ans = 0;
    while (!cows.empty()){
        int a = cows.begin()->first;
        int b = cows.rbegin()-> first;
        ans = max(a + b, ans);

        int ops = min(cows[a], cows[b]);
        cows[a] -= ops;
        cows[b] -= ops;
        if (cows[a] <= 0){
            cows.erase(a);
        }
        if (cows[b] <= 0){
            cows.erase(b);
        }
    }
    cout << ans;
}
