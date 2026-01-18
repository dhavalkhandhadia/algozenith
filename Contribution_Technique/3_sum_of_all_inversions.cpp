#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // 
                ans += (i + 1) * (n - j);
            }
        }
    }

    cout << ans << endl;
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
