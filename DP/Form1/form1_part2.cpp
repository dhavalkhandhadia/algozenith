#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
string s;

int dp[1001][4][2];

int rec(int i, int prev, int cnta){
    int ans = 0;
    //pruning

    //base case
    if(i==n){
        if(cnta==0)return 1;
        else return 0; 
    }
    //cache
    if(prev!=-1 and dp[i][prev][cnta]!=-1)return dp[i][prev][cnta];
    //compute
    if(s[i]=='?'){
        for(int ch=0;ch<4;ch++){
            if(ch==prev)continue;
            ans+=rec(i+1,s[i]-'A',(cnta+(ch==0?1:0))%2);
        }
    }else{
        if(prev==s[i]-'A'){
            ans=0;
        }else{
            ans = rec(i+1,s[i]-'A',(cnta+(s[i]-'A'==0?1:0))%2);
        }
    }

    
    //save and return
    
    if(prev!=-1)dp[i][prev][cnta] = ans;
    
    return ans;

}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,-1,0)<<endl;
    return 0;
}
