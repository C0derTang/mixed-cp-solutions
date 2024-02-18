#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> diffs;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        diffs[a-1] += 1;
        diffs[b-1] -= 1;
    }

    int sum = 0, ans = 0;
    for (auto& [key, value] : diffs) {
        sum += value;
        ans = max(ans, sum);
    }
    cout << ans;
}
