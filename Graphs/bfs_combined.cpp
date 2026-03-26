#include<bits/stdc++.h>
using namespace std;
#define state pair<int,int>
#define endl '\n'
#define F first
#define S second
#define INF 1e7
int n,m;
vector<string> arr;

state start,en; 

int movx[] = {-1,0,1,0};
int movy[] = {0,1,0,-1};

bool isValid(int x, int y){
    if(x>=0 and x<n and y>=0 and y<m and arr[x][y]!='#'){
        return true;
    }else return false;
}

char whichMove(state cur, state next){
    int cur_x = cur.F, cur_y = cur.S;
    int next_x = next.F, next_y = next.S;
    if(next_x-cur_x == 1){
        return 'D';
    }else if(next_x-cur_x ==-1){
        return 'U';
    }else if(next_y-cur_y==1){
        return 'R';
    }else if(next_y-cur_y == -1){
        return 'L';
    }
    
}

vector<vector<int>> dis;
vector<vector<int>> vis;
vector<vector<state>> parent;
vector<state>path;

vector<state> neighbour(state cur){
    vector<state> neighbours;
    for(int i=0;i<4;i++){
        int nx = cur.F + movx[i];
        int ny = cur.S + movy[i];
        if(isValid(nx,ny)){
            neighbours.push_back({nx,ny});
        }
    }

    return neighbours; 
    
}
void bfs(state st){

    dis = vector<vector<int>>(n,vector<int>(m,INF));
    vis = vector<vector<int>>(n,vector<int>(m,0));
    parent = vector<vector<state>>(n,vector<state>(m,{-1,-1}));
    dis[st.F][st.S] = 0;

    queue<state>q;
    
    q.push(st);

    while(!q.empty()){
        state cur = q.front();
        q.pop();
        if(vis[cur.F][cur.S])continue;
        vis[cur.F][cur.S] = 1;
        for(auto neigh:neighbour(cur)){
            if(!vis[neigh.F][neigh.S] and dis[neigh.F][neigh.S]>dis[cur.F][cur.S]+1){
                dis[neigh.F][neigh.S] = dis[cur.F][cur.S]+1;
                parent[neigh.F][neigh.S] = cur;
                q.push({neigh.F,neigh.S});
            }
        }
         
        
    }

}

void printer(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dis[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<endl;
}

void printer2(){
    for(auto cur:path){
        cout<<cur.F<<' '<<cur.S<<endl;
    }
}
void solve(){
    cin>>n>>m;
    
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
                start = {i,j};
            }else if(arr[i][j]=='B'){
                en = {i,j};
            }
        }
    }


    bfs(start);
    printer();
    
    state curr = en;
    
    while(curr!=make_pair(-1,-1)){
        path.push_back(curr);
        curr = parent[curr.F][curr.S];
    }


    reverse(path.begin(),path.end());
    
    printer2();

    cout<<endl;
    cout<<"Answer for cses labyrinth:"<<endl<<endl;
    if(path.size()==1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<path.size()-1<<endl;
    for(int i=0;i<path.size()-1;i++){
        cout<<whichMove(path[i],path[i+1]);
    }


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
