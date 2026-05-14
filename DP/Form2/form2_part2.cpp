#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define state pair<int,int>
#define int long long 

int n;
int arr[1001];

state dp[1001][2];
 state remax(state ans, state pos){
    if(ans.first < pos.first){
        return pos;
    }else if(pos.first == ans.first){
        return {ans.first , ans.second+ pos.second};
    }else{

        return ans;
    }
}
state rec(int i, int dec){
    state ans = {0,0};
    //pruning

    //base case
    
    //cache
    if(dp[i][dec]!= state {-1,-1}){return dp[i][dec];}
    //compute
    if(dec==0){
        ans = {1,1};
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
            state pos = {rec(j,0).first+1,rec(j,0).second};
                ans = remax(ans, pos);
            }
        }
    }else{
        ans = {0,0}; 
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]){
               {
                state pos = {rec(j,0).first+1,rec(j,0).second};
                ans = remax(ans,pos);

               }
               {
                state pos = {rec(j,1).first+1,rec(j,1).second};
                ans = remax(ans,pos);
               }
            }
        }   
    }
    //save and return 
    return ans;
}

void solve(){

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            dp[i][j] = {-1,-1};
        }
    }

    state ans = {0,0};

    for(int i=0;i<n;i++){
        ans = remax(ans, rec(i,1));
        ans = remax(ans, rec(i,0));

    }
    cout<<ans.first<<' '<<ans.second<<endl;

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
