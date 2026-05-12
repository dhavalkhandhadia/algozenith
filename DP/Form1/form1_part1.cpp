#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

#define int long long 
int n;
string s;

int dp[1001][4];

int rec(int i, int prev){
    //pruning

    //base
    if(i==n){
        return 1;
    }
    //cache
    if(prev!=-1 and dp[i][prev]!=-1)return dp[i][prev];


    //compute
    int ans = 0;
    if(s[i]=='?'){
        for(int ch=0;ch<4;ch++){
            
            if(ch==prev)continue;
            ans+=rec(i+1,ch);
        }
    }else{
        if(s[i]-'A'==prev){
            ans = 0;
        }else ans = rec(i+1,s[i]-'A');
    }
    //save and return
    
    return dp[i][prev] = ans;
}


signed main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   cin>>s;
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,-1)<<endl;
   return 0;
}
