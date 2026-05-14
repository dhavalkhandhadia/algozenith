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

    //base case
    if(i==n || j==n){
        return 0;
    }
    //cache
    if(dp[i][j]!=-1)return dp[i][j];
    //compute
    if(s[i]==t[j]){
        ans = rec(i+1,j+1)+1;

    }else{
        ans = max(rec(i+1,j),rec(i,j+1));
    }

    dp[i][j] = ans;
    return ans;
    //save and return

}

void solve(){
    cin>>n;
    cin>>s>>t;
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans, rec(i,j));
        }
    } 

    // or you can choose not to use the nested for loop and go with directly calling : 
    // rec(0,0);
    // however it wont improve your TC  

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
