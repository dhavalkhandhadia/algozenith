#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define state pair<int,int>
#define F first
#define S second
#define INF 1e7
int n, m;
vector<vector<pair<int,int>>> g;
vector<int> vis;
vector<int> dis;


void bfs01(int x){
    
    dis[x] = 0;

    deque<int> q;
    
    q.push_back(x);

    while(!q.empty()){
        int cur = q.front();q.pop_front();
        if(vis[cur])continue;
        vis[cur] = 1;
        

        for(auto [v,w] : g[cur]){
            if(!vis[v] and dis[v]>dis[cur]+w){
                dis[v] = dis[cur]+w;
                if(w==0){
                    q.push_front(v);
                }else{
                    q.push_back(v);
                }
            }
        }
    }


}

void solve(){

    cin>>n>>m; 
    g.resize(n+1);
    vis = vector<int>(n+1,0);
    dis = vector<int>(n+1,INF);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }

    bfs01(1);
    
    for(auto d : dis){
        cout<<d<<' ';
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve(); 


    return 0;
}
