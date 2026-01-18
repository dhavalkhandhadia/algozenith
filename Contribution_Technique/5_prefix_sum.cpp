#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long total = 0;
    long long curans = 0;

    for (int i = 0; i < n; i++) {
        curans = curans + arr[i];   // prefix sum
        total += curans * curans;   // add square of prefix sum
    }

    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
