#include<bits/stdc++.h>

#define endl '\n'
#define int long long 
using namespace std;

vector<int> calc_pse(int n, vector<int> arr){
    vector<int> pse(n);

    stack <int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() and arr[i]<=arr[st.top()]){
            st.pop();
        }

        if(st.empty()){
            pse[i] = -1;
        }else{
            pse[i] = st.top();
        }
            st.push(i);
        
    }


    return pse;
}

vector<int> calc_nse(int n, vector<int> arr){

    vector<int>nse(n);
    stack<int>st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() and arr[i]<=arr[st.top()]){
            st.pop();
        }

        if(st.empty()){
            nse[i] = n;
            
        }else{
            nse[i] = st.top();
        }

        st.push(i);
    }

    return nse;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> nse = calc_nse(n,arr);
    vector<int> pse = calc_pse(n,arr);
    int peri =0;
    int area = 0;
    for(int i=0;i<n;i++){
        int l = pse[i]+1;
        int r = nse[i]-1;
        
        int height = arr[i];
        int width  = r-l+1;

        peri = 2*(height+width)>peri? 2*(height+width): peri;
        area = height*width> area ? height*width : area;
        }
    
    cout<<peri<<' '<<area;

    return 0;
}
