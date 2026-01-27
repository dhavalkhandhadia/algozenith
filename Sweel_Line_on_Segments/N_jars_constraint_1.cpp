#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    set<int> jars[n + 1];

    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;

        for (int j = l; j <= r; j++) {
            jars[j].insert(k);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << jars[i].size() << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
