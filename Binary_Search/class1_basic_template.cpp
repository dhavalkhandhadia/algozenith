#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'


bool check_mid(vector<int> &a, int mid){
    if(a[mid] == 1){
        return 0;
    }

    return 1;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int low = 0,high =n-1,mid = (high+low)/2, ans =-1;
    while(low<=high){
        if(check_mid(arr,mid)){
            low = mid+1;
        }else{
            ans = mid;
            high = mid-1;
        }
            mid = (high+low)/2;

    }

    cout<<ans;

    return 0;
}
