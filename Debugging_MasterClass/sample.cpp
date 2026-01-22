#include<bits/stdc++.h>
using namespace std;

int solveslow(int n, int arr[],int x){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==x)cnt++;
        }
    }
    return cnt;
}

int solve(int n, int arr[],int x){ // 
    int cnt = 0;
    int lo = 0, hi = n-1;
    while(lo<hi){
        if(arr[lo]+arr[hi]==x){

            int t1 = lo;
            while(t1<n&&arr[t1]==arr[lo])t1++;

            int t2 = hi;
            while(t2>=0&&arr[t2]==arr[hi])t2--;
            if(arr[lo]==arr[hi]){
                cnt+= (t1-lo)*(t1-lo-1)/2;
            }
            else cnt += (t1-lo) * (hi-t2);
            lo=t1;hi=t2;
        }else if(arr[lo]+arr[hi]>x){
            hi--;
        }else{
            lo++;
        }
    }
    return cnt;
}

int random_num(int x,int y){//[x...y]
    return x+rand()%(y-x+1);
}

bool generator(){
    int n;
    n = random_num(1,5);
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i] = random_num(1,10);
    }
    sort(arr,arr+n);
    int x;
    x=random_num(1,20);

    if(solve(n,arr,x)!=solveslow(n,arr,x)){
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<x<<endl;
        cout<<endl;

        cout<<"My code: "<<solve(n,arr,x)<<endl;
        cout<<"Correct solution: "<<solveslow(n,arr,x)<<endl;
        return true;
    }else{
        return false;
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    srand(time(0)); // Seed random.

    // while(!generator());


    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<solve(n,arr,x)<<endl;
}