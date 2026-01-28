#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> allevents;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        allevents.push_back({l,+1});
        allevents.push_back({r+1,-1});
    }
    allevents.push_back({1,0});
    allevents.push_back({x+1,0});

    sort(allevents.begin(),allevents.end());

    vector<int> covered_by(n+1,0);

    int cnt = 0;
    for(int i=0;i<allevents.size();i++){
        cnt += allevents[i].second;
        if(i+1<allevents.size()){
            int days = allevents[i+1].first - allevents[i].first;
            covered_by[cnt]+=days;
        }
    }

    for(int i=0;i<=n;i++){
        cout<<covered_by[i]<<" ";
    }
    cout<<endl;
    for(int i=n-1;i>=0;i--){ // Suffix sum
        covered_by[i]+=covered_by[i+1];
    }
    for(int i=0;i<=n;i++){
        cout<<covered_by[i]<<" ";
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}