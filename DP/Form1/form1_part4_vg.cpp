#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
string s;

int dp[1001][4][2];

int rec(int i, int prev, int cnta){
    int ans = 0;

    if(i==n){
        if(cnta==0) return 1;
        else return 0; 
    }

    if(prev!=-1 && dp[i][prev][cnta]!=-1) return dp[i][prev][cnta];

    if(s[i]=='?'){
        for(int ch=0; ch<4; ch++){
            if(ch==prev) continue;
            ans += rec(i+1, ch, (cnta+(ch==0?1:0))%2);
        }
    }else{
        int ch = s[i]-'A';

        if(prev==ch){
            ans=0;
        }else{
            ans = rec(i+1, ch, (cnta+(ch==0?1:0))%2);
        }
    }

    if(prev!=-1) dp[i][prev][cnta] = ans;
    
    return ans;
}

string ans;

void build(int i, int prev, int cnta){
    if(i==n){
        return;
    }

    if(s[i]=='?'){
        for(int ch=0; ch<4; ch++){
            if(ch==prev) continue;

            if(rec(i+1, ch, (cnta+(ch==0?1:0))%2)>0){
                ans += char('A'+ch);
                build(i+1, ch, (cnta+(ch==0?1:0))%2);
                return;
            }
        }
    }else{
        int ch = s[i]-'A';

        ans += s[i];
        build(i+1, ch, (cnta+(ch==0?1:0))%2);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> s;

    memset(dp, -1, sizeof(dp));

    int total = rec(0, -1, 0);
    cout << total << endl;

    if(total > 0){
        build(0, -1, 0);
        cout << ans << endl;
    }else{
        cout << "Not Possible" << endl;
    }

    return 0;
}
