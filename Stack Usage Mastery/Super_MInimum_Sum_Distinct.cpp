
#include <bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;

vector<int> calc_pse(int n, vector<int>arr){
    vector<int>pse(n);
    for(int i=0;i<n;i++){
        pse[i] = i-1;
        while(pse[i]!=-1 and arr[i]<=arr[pse[i]]){
            pse[i] = pse[pse[i]];
        }
    }
    return pse;

}

vector<int> calc_nse(int n, vector<int>arr){
    vector<int>nse(n);

    for(int i=n-1;i>=0;i--){
        nse[i]= i+1;
        while(nse[i]!=n and arr[i]<=arr[nse[i]]){
            nse[i] = nse[nse[i]];
        }

    }
    return nse;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        vector<int>pse = calc_pse(n,arr);
        vector<int>nse = calc_nse(n,arr);
        int sum = 0;
        for(int i=0;i<n;i++){
            int l = i-pse[i];
            int r = nse[i]-i;

            sum+= arr[i]*(l*r);

        }

        cout<<sum<<endl;
    }


    return 0;
}
