#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    set<int> stprev;
    int best = 1e9;

    for (int j = 0; j < n; j++) {
        int ivalsgreater = x - arr[j];

        auto it = stprev.lower_bound(ivalsgreater);
        if (it != stprev.end()) {
            best = min(best, *it + arr[j]);
        }

        stprev.insert(arr[j]);
    }

    cout << best << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
