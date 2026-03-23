#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
vector<vector<int>> g;

vector<int> vis;
void printer(){

    for(auto v: vis){
        cout<<v<<" ";
    }
    cout<<endl;
}
void dfs(int node){
    vis[node] = 1;
    for(auto neighbour : g[node]){
        if(!vis[neighbour]){
            dfs(neighbour);
        }
    }

}

void solve(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vis.resize(n+1,0);

    
    dfs(1);
    printer();



}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
