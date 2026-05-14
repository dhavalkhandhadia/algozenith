#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

#define int long long 

int n;
int arr[1001];

int dp[1001][2];

int rec(int i, int dec){
    int ans = 0;
    //pruning

    //base case
    
    //cache
    if(dp[i][dec]!=-1)return dp[i][dec];
    //compute
    if(dec==0){
        ans = 1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                ans = max(ans, rec(j,0)+1);
            }
        }
    }else{
        ans = 0; 
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]){
                ans = max(ans, max(rec(j,0),rec(j,1)) + 1 );
            }
        }   
    }
    //save and return 
    dp[i][dec] = ans;
    return ans;
}

void solve(){

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans = 0;

    for(int i=0;i<n;i++){
        ans = max(ans, rec(i,1));
        ans = max(ans, rec(i,0));

    }
    cout<<ans<<endl;

}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;

    // cin>>t;
    t=1;

    while(t--){
        solve();
    }

    return 0;
}
