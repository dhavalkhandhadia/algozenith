#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

vector<int> calc_nge(int n, vector<int> arr) {
    vector<int> nge(n);

    for (int i = n - 1; i >= 0; i--) {
        nge[i] = i + 1;

        while (nge[i] != n && arr[nge[i]] <= arr[i]) {
            nge[i] = nge[nge[i]];
        }
    }

    return nge;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> nge = calc_nge(n, arr);

    
    for (int i = 0; i < n; i++) {
        if (nge[i] == n)
            cout << -1 << " ";
        else
            cout << nge[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
