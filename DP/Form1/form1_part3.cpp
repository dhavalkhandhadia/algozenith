#include <bits/stdc++.h>
using  namespace std;

#define int long long 

#define endl '\n'

int n;
string s;
int dp[1001][4][2][4];
int rec(int i, int prev, int cnta, int first){
    int ans= 0;
    //pruning
     
    //base check
    if(i==n){
        if(cnta==0 and first!=prev)return 1;
        else return 0;
    }
    //cache
    if(prev!=-1  and dp[i][prev][cnta][first]!=-1)return dp[i][prev][cnta][first];
    //compute

    if(s[i]=='?'){
        for(int ch=0;ch<4;ch++){
            if(prev==ch)continue;
            if(first==-1){
                ans+=rec(i+1,ch,(cnta+(ch==0?1:0))%2,ch);

            }else{
                 ans+=rec(i+1,ch,(cnta+(ch==0?1:0))%2,first);
            }
           
        }
    }else{
      
        if(s[i]-'A'==prev)ans=0;
        else{
            ans = rec(i+1, s[i]-'A',(cnta+(s[i]-'A'==0?1:0))%2,first);
        }
    }
    //save and return 
    if(prev!=-1) dp[i][prev][cnta][first] = ans;
    return ans;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    cin>>s;
    memset(dp,-1,sizeof(dp));

    cout<<rec(0,-1,0,s[0]=='?'?-1:s[0]-'A')<<endl;

    return 0;
}
