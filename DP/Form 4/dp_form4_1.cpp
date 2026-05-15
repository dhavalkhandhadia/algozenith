#include<bits/stdc++.h>
using namespace std;

#define endl '\n'


int n;
int nums(302);


int rec(int l, int r){

//pruning 

//base case
    if(l>r)return 0;
//cache check

//compute 
    int ans = 0;

    for(int i = l;i<=r;i++){
        ans = max(ans, rec(l,i-1)+rec(i+1,r)+(nums[i]*nums[l-1]*nums[r+1]));
    }
//save and return 
    return ans;
}

void solve(){
   
    cin>>n;
    
    
    
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }   


    nums[0] = 1;
    nums[n+1] = 1;


    cout<<rec(1,n)<<endl;
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
