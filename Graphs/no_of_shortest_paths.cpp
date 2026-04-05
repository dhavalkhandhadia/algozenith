#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define INF  100
#define F first
#define S second

using state = pair<int,int>; //another name for pair

int n,m;
vector<string>arr;
vector<vector<int>> ways;
int count1 =  0;
bool isValid(int x, int y){
    if(x>=0 and x<n and y>=0 and y<m and arr[x][y]!='#'){
        return 1;
    }else return 0;
}

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

vector<state> neighbours(state cur){

    vector<state> neigh;
    for(int dir=0;dir<4;dir++){
        int nx = cur.F + dx[dir];
        int ny = cur.S + dy[dir];

        if(isValid(nx,ny))neigh.push_back({nx,ny});
        
    }
    return neigh;
}


int distance = 0;
vector<vector<int>>vis , dist;
void printer(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dist[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
}
void bfs(state st){ 
    //sssp - single source shortest path, when run from one node we get distance of all the nodes from that node
    ways = vis = vector<vector<int>> (n,vector<int>(m,0));

    vis = vector<vector<int>> (n,vector<int>(m,0));

    dist = vector<vector<int>>(n,vector<int>(m,INF));

    queue<state> q;

    dist[st.F][st.S] = 0;
    q.push(st);
    ways[st.F][st.S] = 1;
    while(!q.empty()){
        state cur = q.front();
        q.pop();

        if(vis[cur.F][cur.S])continue;
        vis[cur.F][cur.S]=1;
        //go through neighbours

        for(auto neigh: neighbours(cur)){
            //bfs finds the best distance in the first go 
            if(!vis[neigh.F][neigh.S] and dist[cur.F][cur.S]+1< dist[neigh.F][neigh.S]){
                dist[neigh.F][neigh.S] = dist[cur.F][cur.S]+1;
                ways[neigh.F][neigh.S] = ways[cur.F][cur.S];
                q.push(neigh);
            }
            else if(dist[cur.F][cur.S]+1 == dist[neigh.F][neigh.S]){
                ways[neigh.F][neigh.S] += ways[cur.F][cur.S];
            }
        }

    }


}

void solve(){
    cin>>n>>m;

    arr.resize(n);
    int a,b;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    state st,en;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
                st={i,j};
            }else if(arr[i][j]=='B'){
                en = {i,j};
            }
        }
    }

    bfs(st);
    printer();
    cout<<endl;
    cout<<ways[en.F][en.S];
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



    solve();

    return 0;
}


/* 

Test case : 

19 20
####################
#A.................#
#..................#
#..................#
#..................#
#..................#
#..................#
#..................#
#..................#
#..................#
#..................#
#..................#
#..................#
#..................#
#..................#
#..................#
#..................#
#.................B#
####################

Correct Ans : No of Shortest Paths = 1166803110
*/
