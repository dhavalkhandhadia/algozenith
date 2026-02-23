
#include <bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;

int freq_arr[1000100];
int distinct_count= 0;

void insert(int x){
    if(!freq_arr[x]++){
        distinct_count++;
    }
}

void remove(int x){
    if(!--freq_arr[x]){
        distinct_count--;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int head = -1, tail = 0;
    int ans = 0;

    while(tail<n){
        while(head+1<n and (freq[arr[head+1]]>0 || distinct_count<k) ){
            head++;
            insert(arr[head]);
        }
        ans += head - tail + 1; 
        if(tail<=head){
            remove(arr[tail]);
            tail++;
        }else{
            tail++;
            head = tail-1;
        }
    }


    cout<<ans<<endl;
    
    
    return 0;
}
