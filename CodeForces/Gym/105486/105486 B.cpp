#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;

#define read()          freopen("folding.in","r",stdin)
#define write()         freopen("folding.out","w",stdout)

#define ff              first
#define ss              second
#define pb              push_back
#define endl            "\n"
#define ll              long long
#define double          long double
#define ull             unsigned long long
#define all(x)          x.begin(), x.end()
#define rall(x)         x.rbegin(), x.rend()
#define uniq(x)         unique(x.begin(), x.end()) - x.begin()
#define deci(x)         cout << fixed << setprecision(x);
#define war()           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

const ll LLMax = 1e18;
const ll LLMin = -1e18;
//const ll MOD   = 1e9+7;
const double PI = acos(-1);       //3.1415926535897932384626

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};

//pbds
//template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//template<typename T>using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

//debug
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define db(x)
#endif

//sc
template<typename T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x : a) cin >> x; return cin; }

// nCr = n! / r! * (n-r)!
// nPr = n! / (n-r)!
// .order_of_key(x)
// *    .find_by_order(x)
//substr
//cin.ignore();
//__builtin_popcount()
//memset(dp, -1, sizeof(dp));
//cout<<"Case "<<T<<": ";


#define YES {cout<<"Yes"<<endl;}
#define NO  {cout<<"No"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

const ll MOD= 1e9+7;
const int N=302;
int dp[N][N][N][4];   //0=agea kisu nai
int arr[N];
int n;  

#define int ll

int xxx(int pos, int a, int b, int c, int last){
    if(pos==n){return 1;}
    
    if(dp[pos][a][b][last]!=-1){return dp[pos][a][b][last];}
    
    int ans=0;
    if(arr[pos]==last && last!=0){return 0;}
    if(arr[pos]!=0){ans+=xxx(pos+1, a, b, c, arr[pos]);}
    else{
        if(last!=1 && a>0){ans+=xxx(pos+1, a-1, b, c , 1);}
        if(last!=2 && b>0){ans+=xxx(pos+1, a, b-1, c , 2);}
        if(last!=3 && c>0){ans+=xxx(pos+1, a, b, c-1 , 3);}
    }
    return dp[pos][a][b][last]=ans%MOD;
}





void solve(int T){            ///   (DRINK WATER)
    cin>>n;     
    int q; cin>>q;
    string s;   cin>>s;
    
    int ques_mask=0;
    for(int i=0; i<n; i++){
        if(s[i]=='?'){ques_mask++; arr[i]=0;}
        else{arr[i]=s[i]+1-'a';}
    } 

    //gen dp
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<=ques_mask; i++){
        for(int j=0; j<=ques_mask; j++){
            int c=ques_mask-i-j;
            if(c<0){break;}
            int z=xxx(0, i, j, c, 0);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                for(int l=0; l<4; l++){
                    if(dp[i][j][k][l]==-1){dp[i][j][k][l]=0;}
                }
            }
        }
    }


    int presum[N][N];
    memset(presum, 0, sizeof(presum));

    for(int i=0; i<N; i++){
        int sum=0;
        for(int j=0; j<N; j++){
            sum=(sum+dp[0][i][j][0])%MOD;
            presum[i][j]=sum;
        }
    }

    while(q--){
        int x,y,z;  cin>>x>>y>>z;
        int ans=0;
        for(int i=0; i<=x; i++){
            int j_min = max(0ll,ques_mask-i-z);
            int j_max = min(y,ques_mask-i);
            if(j_min>j_max){continue;}
            ans=(ans+presum[i][j_max])%MOD;
            j_min--;
            if(j_min>=0){ans=(ans+MOD-presum[i][j_min])%MOD;}
        }
        cout<<ans<<endl;
    }
}

 




int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////
    
    /////////////////////////////////////
    int tc=1;
    //cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}