#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define INF 1000
vector<vector<int>> g;
vector<int> ans,arr;

void dfs(int node, int prev, int minseen, int maxseen){

    ans[node] = (abs(minseen-arr[node]),abs(maxseen-arr[node]));

    minseen  = min(minseen, arr[node]);
    maxseen  = max(maxseen, arr[node]);

    for(auto i : g[node]){
        if(i!=pp){
        dfs(i,node, minseen, maxseen);
        }
    }
}

int main(){
    int b,m;
    cin>>n>>m;

    g.resize(n+1);
    arr.resize(n+1);
    ans.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);

    }

    dfs(1,0,INF,-INF);
    for(auto i: ans){
        cout<<ans[i]<<endl
    }
    return 0;
}
