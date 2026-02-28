#include <bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;

signed  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int l = 0, r = n - 1, ans = 0;

        while (l < r) {
            ans = max(ans, min(arr[l], arr[r]) * (r - l));

            if (arr[l] < arr[r])
                l++;
            else
                r--;
        }

        cout<<ans;

    
    return 0;
}
