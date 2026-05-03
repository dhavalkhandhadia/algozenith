#include <bits/stdc++.h>
using namespace std;

int n, x;
int arr[1001];
int dp[1001][1001];

int rec(int i, int cursum) { // dp value
    // pruning
    if (cursum > x) return 0;

    // base case
    if (i == n) {
        if (cursum == x) return 1;
        else return 0;
    }

    // cache check
    if (dp[i][cursum] != -1) return dp[i][cursum];

    // transition
    int ans = rec(i + 1, cursum + arr[i]) + rec(i + 1, cursum);

    // save and return
    dp[i][cursum] = ans;
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
