#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
int count1 = 0;
int p[51], b[51];
void precom(){
    p[0] = 1;
     b[0]=0;
for(int i=1;i<51;i++){
    p[i] = 2*p[i-1]+1;
    b[i] = 2*b[i-1]+2;
}
}
void kthmove(int n, int x){
   if(n==0){
    count1++;
    return;
   }

  if(x==1)return;
 else if(x<=p[n-1]+b[n-1]+1){
    kthmove(n-1,x-1);
    
 }else if(x==p[n-1]+b[n-1]+2){
    count1+=p[n-1]+1;
    return;
 } else if(x<=2*(p[n-1]+b[n-1])+2){
    count1+=p[n-1]+1;
    kthmove(n-1,x-2-p[n-1]-b[n-1]);
 }else if(x==2*(p[n-1]+b[n-1])+3){
    count1+=2*(p[n-1])+1;
    return;
 }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    precom();
    kthmove(n,x);
    
    cout<<count1<<endl;


}
