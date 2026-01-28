#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;


    vector<vector<pair<int,int>>> events(n + 2);

    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        events[l].push_back({+1, k});
        events[r + 1].push_back({-1, k});
    }

    map<int,int> curjarfreq; 

    for (int i = 1; i <= n; i++) {
        for (auto v : events[i]) {
            if (v.first == +1) {
                curjarfreq[v.second]++;
            } else {
                curjarfreq[v.second]--;
                if (curjarfreq[v.second] == 0) curjarfreq.erase(v.second);
            }
        }
        cout << (int)curjarfreq.size() << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t ;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
