#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
vector<vector<int>> g;

vector<int> vis;
vector<int>comp;
vector<int> reachable;
void printer(int n){

    for(int i=1;i<=n;i++){
        cout<<comp[i]<<" : "<<reachable[comp[i]]<<endl;
    }
    cout<<endl;
}
void dfs(int node,int comp_no){
    vis[node] = 1;
    comp[node] = comp_no;
    for(auto neighbour : g[node]){
        if(!vis[neighbour]){
            comp[neighbour] = comp_no;
            dfs(neighbour,comp_no);
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
    comp.assign(n+1,0);
    reachable.assign(n+1,0);
    int comp_no = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            comp_no++;
            dfs(i,comp_no);
        }
    }

    for(int i=1;i<=n;i++){
        reachable[comp[i]]++;
    }

    printer(n);



}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
