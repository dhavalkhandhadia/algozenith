#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
vector<vector<int>> g;
vector<int>colour;
vector<int> vis;
bool is_bipartite = true;
void dfs(int node,int col){
    vis[node] = 1;
    colour[node] = col;
    for(auto neighbour : g[node]){
        if(!vis[neighbour]){
            dfs(neighbour,3-col);
        }else if(colour[neighbour] == colour[node]){
            is_bipartite = false;
            return ;  
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
    vis.assign(n+1,0);
    colour.assign(n+1,0);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            
            dfs(i,1);
        }
    }

    
    if(is_bipartite){
        for(int i=1;i<=n;i++){
            cout<<i<<" : "<<colour[i]<<endl;
        }
    }


}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
