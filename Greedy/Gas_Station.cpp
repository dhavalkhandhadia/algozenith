#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve(){
    int n;
    cin >> n;
    int p[n];
    int r[n];
    int c[n];

    for(int i = 0; i < n - 1; i++){
        cin >> p[i] >> r[i] >> c[i];
    }

    priority_queue<pair<int,int>> pq;

    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        pq.push({-p[i], r[i]});
        int left = c[i];

        while(!pq.empty() && left > 0){
            pair<int,int> temp = pq.top();
            pq.pop();

            // [-p, r].
            int used = min(temp.second, left);
            left -= used;
            temp.second -= used;
            ans += (-temp.first) * used;

            if(temp.second != 0){
                pq.push(temp);
            }
        }

        if(left > 0){
            ans = -1;
            break;
        }
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
