#include <bits/stdc++.h>
#define int long long 
using namespace std;
#define endl '\n'

int pow(int x){
    int ans = 1;
    for(int i=0;i<x;i++){
        ans*=2;
    }
    return ans;
}

void moves(int curr, int target, int extra, int number_of_disks, int k){   
    int sub_call_moves = pow(number_of_disks-1)-1;
    if(k<=sub_call_moves){
        moves(curr,extra,target,number_of_disks-1,k);
    }
    else if(k==sub_call_moves+1){
        cout<<curr<<"-->"<<target<<endl;
        return;
    }else{
        moves(extra,target,curr,number_of_disks-1,k-sub_call_moves-1);
    }

}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    moves(1,3,2,5,7);

    return 0;
}
