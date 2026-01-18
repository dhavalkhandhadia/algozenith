#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    map<int, int> mp;
    int cnt = 0;

    for (int j = 0; j < n; j++) {
        int vali = x - arr[j];
        cnt += mp[vali];
        mp[arr[j]]++;
    }

    cout << cnt << endl;
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
