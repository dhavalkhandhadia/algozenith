#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

 int freq_arr[1000100];
 int distinct_count = 0;

void insert_val(int x){
    if (!freq_arr[x]++) distinct_count++;
}
void remove_val(int x){
    if (!--freq_arr[x]) distinct_count--;
}

int count_at_most_k_distinct(int n, int k, const vector<int>& arr){
    if (k < 0) return 0;

    
    distinct_count = 0;
   
    memset(freq_arr, 0, sizeof(freq_arr));

    int head = -1, tail = 0;
    long long ans = 0;

    while (tail < n){
        while (head + 1 < n && (freq_arr[arr[head+1]] > 0 || distinct_count < k)){
            head++;
            insert_val(arr[head]);
        }
        ans += (head - tail + 1);

        if (tail <= head){
            remove_val(arr[tail]);
            tail++;
        } else {
            tail++;
            head = tail - 1;
        }
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = count_at_most_k_distinct(n, k, arr) - count_at_most_k_distinct(n, k-1, arr);
    cout << ans << endl;
    return 0;
}
