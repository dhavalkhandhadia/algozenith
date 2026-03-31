#include <bits/stdc++.h>
#define endl '\n'
#define INF 1e9
#define state pair<int,int>
using namespace std;
#define F first
#define S second

int n,m;
vector<int>vis;
vector<vector<state>>g;
vector<int> dis;


void dijkstra(int st){
    dis[st] = 0;

    priority_queue<state>q;

    q.push({-0,st});

    while(!q.empty()){
        state cur = q.top();
        q.pop();
        
        if(vis[cur.S]) continue;
        vis[cur.S] = 1;

        for(auto [v,w] : g[cur.S]){
            if(!vis[v] and dis[v] > dis[cur.S] + w){
                dis[v] = dis[cur.S] + w;
                q.push({-1*dis[v],v}); 
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

    dijkstra(1);
    for(auto d : dis){
        cout<<d<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

/* a test case to see how its running : 
   5 6
   1 2 4
   1 3 1
   3 2 2
   2 5 4
   3 4 4
   4 5 4   
   
   Answer : 1 : 0
            2 : 3
            3 : 1
            4 : 5 
            5 : 7

   */
