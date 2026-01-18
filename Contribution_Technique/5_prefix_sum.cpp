#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int total = 0;
    int curans = 0;

    for (int i = 0; i < n; i++) {
        curans = curans * arr[i] + arr[i];
        total += curans;
    }

    cout << total << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
