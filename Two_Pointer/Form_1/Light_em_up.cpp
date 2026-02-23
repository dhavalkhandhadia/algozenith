#include <bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int head = -1, tail = 0;
    int ans = 0, no_of_zeros = 0;

    while(tail<n){
        while(head+1<n and (arr[head+1]==1 || no_of_zeros<k) ){
            head++;
            if(arr[head]==0)no_of_zeros++;
        }
        ans = max(ans,head - tail + 1);
        if(tail<=head){
            if(arr[tail]==0){
                no_of_zeros--;
            }
            tail++;
        }else{
            tail++;
            head = tail-1;
        }
    }


    cout<<ans<<endl;
    
    
    return 0;
}
