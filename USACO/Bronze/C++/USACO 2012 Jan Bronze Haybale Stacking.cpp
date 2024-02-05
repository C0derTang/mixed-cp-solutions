#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> diff(n, 0);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        ++diff[a-1];
        --diff[b]; // Ensure b is within bounds
    }

    vector<int> pref(n+1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i+1] = pref[i] + diff[i];
    }

    sort(pref.begin(), pref.end());
    cout << pref[(n+1)/2] << endl;
}