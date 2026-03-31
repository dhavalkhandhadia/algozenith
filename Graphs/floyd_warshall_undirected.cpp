#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define state pair<int,int>
#define F first
#define S second
#define INF 1e9

int n,m;
vector<vector<int>>dis;


void floyd_warshall(){

    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }

    
}

void solve(){
    cin>>n>>m;

    dis = vector<vector<int>>(n+1,vector<int>(n+1,INF));
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i==j){
                dis[i][j] = 0;
            }
        }
    }
    for(int i=0;i<m;i++){
        int x,y,z;
    
        cin>>x>>y>>z;

        dis[x][y] = min(dis[x][y],z);
        dis[y][x] = min(dis[y][x],z);

    }

    

    floyd_warshall();


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<'\t';
        }   
        cout<<endl;
}
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
