// https://toph.co/p/sofdor-ali-and-radioactivity

#include<bits/stdc++.h>                                         //DRINK WATER
using namespace std;

#define endl            "\n"
#define ll              long long


#define war()           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const ll MOD   = 1e9+7;


#define int ll

const int N=55;

ll dp[N];

vector<vector<int>> matrix_mul(vector<vector<int>>P1, vector<vector<int>>P2, int a, int b_c, int d, int M){
    vector<vector<int>>res(N, vector<int>(N));
    for(int i=0; i<a; i++){
        for(int j=0; j<d; j++){
            ll ans=0;
            for(int k=0; k<b_c; k++){
                ans= (ans + ((1ll*P1[i][k] * P2[k][j])%M))%M;   //iniatilize ll if needed
            }
            res[i][j]=ans;
        }
    }
    return res;
}

vector<vector<int>> matrix_pow(vector<vector<int>>P, ll n, int sz, ll M){
    vector<vector<int>>I(N,vector<int>(N));
    for(int i=0; i<sz; i++){I[i][i]=1;}
    
    while(n){
        if(n&1){
            I=matrix_mul(I,P,sz,sz,sz,M);
        }
            P=matrix_mul(P,P,sz,sz,sz,M);
        n>>=1;
    }
    return I;
}

ll M_er_jonno_dp(int x){
    if(x==0){return 1;}
    if(x<0){return 0;}
    else if(dp[x]!=-1){return dp[x];}

    ll ans=0;

    for(int i=1; i<=x; i++){
        ans=(ans+M_er_jonno_dp(x-i))%MOD;
    }   
    return dp[x]=ans; 
}



void solve(int T){            ///   (DRINK WATER)
    ll n,m;    cin>>n>>m;

    memset(dp, -1, sizeof dp);
    M_er_jonno_dp(m);

    cout<<"Case "<<T<<": ";

    if(n<=m){cout<<M_er_jonno_dp(n)<<endl; return;}

    vector<vector<int>>Seq(N,vector<int>(N));
    vector<vector<int>>Pat(N,vector<int>(N));

    for(int i=0; i<m; i++){
        Pat[i][0]=M_er_jonno_dp(m-i);
        Seq[0][i]=1;
    }

    for(int i=1; i<m; i++){
        Seq[i][i-1]=1;
    }
    
    Seq=matrix_pow(Seq, n-m, m, MOD); 
    Pat=matrix_mul(Seq, Pat, m, m, 1,MOD);
    cout<<Pat[0][0]<<endl;
return;
}






int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////

    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}