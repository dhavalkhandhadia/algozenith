#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define state pair<int,int>
#define F first
#define S second
#define INF 1e9

int n,m;
vector<pair<int,state>> edges;
vector<int>dis;
bool negative_loop = false;

void bellman_ford(int st){
    dis[st] = 0;

    for(int i=0;i<n-1;i++){
        for(auto edge: edges){
            auto [u,v] = edge.S;
            if(dis[v]>dis[u]+edge.F){
                dis[v] = dis[u]+edge.F;
            }
        }
    }

    for(auto edge:edges){
        auto [u,v] = edge.S;
            if(dis[v]>dis[u]+edge.F){
                negative_loop = true;
                 break;
            } 
    }
}


void solve(){
    cin>>n>>m;

    dis.assign(n+1,INF);

    for(int i=0;i<m;i++){
        int x,y,z;
    
        cin>>x>>y>>z;

        edges.push_back({z,{y,x}});
        edges.push_back({z,{x,y}});
    }

    int st;
    cin>>st;

    bellman_ford(st);

    if(negative_loop){
        cout<<"Negative Loop is Present";
    }else{
        for(int i=1;i<n+1;i++){
            cout<<i<<' '<<dis[i]<<endl;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
