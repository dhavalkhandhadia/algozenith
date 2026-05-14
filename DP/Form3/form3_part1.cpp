#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'

int n;
string s,t;

int dp[1001][1001];

int rec(int i, int j){
    int ans = 0;
    //pruning

    //base check
    if(i==n || j==n){
        return 0;
    }
    //cache
    if(dp[i][j] != -1) return dp[i][j];

    //compute
    if(s[i]==t[j]){
        ans = 1 + rec(i+1,j+1);
    }else if(s[i]!=t[j]){
        ans = 0;
    }

    dp[i][j] = ans;
    return ans;
    //save and return
}


void solve(){

    cin>>n;
    cin>>s>>t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            ans = max(ans, rec(i,j));
        }
    }

    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    // cin>>t;

    t = 1;
    while(t--){
        solve();
    }

    return 0;
}
