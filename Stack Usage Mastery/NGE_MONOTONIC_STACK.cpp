#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
a#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

vector<int> calc_nge(int n, vector<int> arr) {
    vector<int> nge(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            nge[i] = n;
        } else {
            nge[i] = st.top();
        }

        st.push(i);
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
        if (nge[i] == n) cout << -1;
        else cout << nge[i];
        if (i + 1 < n) cout << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}

vector<int> calc_nge(int n, const vector<int>& arr) {
    vector<int> nge(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return nge;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> nge = calc_nge(n, arr);

    for (int i = 0; i < n; i++) {
        cout << (nge[i] == n ? -1 : nge[i]) << (i + 1 == n ? '\n' : ' ');
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
