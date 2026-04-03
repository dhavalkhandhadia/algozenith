#include<bits/stdc++.h>
using namespace std;

#define INF 100
#define F first
#define S second

int n,m,k;
vector<string> arr;
using state = pair<pair<int,int>,int>;


bool is_valid(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    else return 0;
}

#define DIR 4
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

vector<state> neighbours(state cur){
    vector<state> neigh;
    for(int dir =0;dir<DIR;dir++){
        int nx = cur.F.F + dx[dir];
        int ny = cur.F.S + dy[dir];
        if(is_valid(nx,ny)){
            int nw = cur.S;
            if(arr[nx][ny]=='#')nw++;
            if(nw>k)continue;
            neigh.push_back({{nx,ny},nw});
        }
    }
    return neigh;
}

vector<vector<vector<int>>> vis,dist;

void bfs(state st){
    queue<state> q;
    vis.assign(n,vector<vector<int>>(
            m, vector<int>(
                k+1,0
        )
    ));
    dist.assign(n,vector<vector<int>>(
            m, vector<int>(
                k+1,INF
            )
    ));
    // push the start node.
    dist[st.F.F][st.F.S][st.S]=0;
    q.push(st);
    while(!q.empty()){
        auto cur = q.front();q.pop();
        
        if(vis[cur.F.F][cur.F.S][cur.S])continue;
        vis[cur.F.F][cur.F.S][cur.S] = 1;

        for(auto v:neighbours(cur)){
            if(!vis[v.F.F][v.F.S][v.S] &&
                dist[v.F.F][v.F.S][v.S] > dist[cur.F.F][cur.F.S][cur.S]+1){
                dist[v.F.F][v.F.S][v.S] = dist[cur.F.F][cur.F.S][cur.S]+1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;k=n+m;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair<int,int> st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S'){
                st = {i,j};
            }else if(arr[i][j]=='E'){
                en = {i,j};
            }
        }
    }

    k = abs(st.F-en.F) + abs(st.S-en.S);

    bfs({st,0});

    int ans = INF;
    for(int i=0;i<=k;i++){
        ans = min(ans, dist[en.F][en.S][i]);
        cout<<ans<<endl;
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
/* test case from class 

5 5
S#...
##.#.
...#.
####.
.E... 

*/
