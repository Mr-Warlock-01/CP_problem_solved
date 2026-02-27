#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;

#define read()          freopen("cooling.in","r",stdin)
#define write()         freopen("cooling.out","w",stdout)

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
#define war()           ios::sync_with_stdio(0); cin.tie(0);

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
// *.find_by_order(x)
//substr
//cin.ignore();
//get<idx>(z) //tuple
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

ll gcd(ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}
ll lcm(ll a, ll b){return ((a/gcd(a,b))*b);}

//#define int ll
//const int N=1e5+7;
int n,m;    
pair<int,int>p,f;

int not_connected(vector<vector<char>>&v){
    int ans=0;
    vector<vector<bool>>vis(n,vector<bool>(m));
    queue<pair<int,int>>pq;
    pq.push({p.ff, p.ss});
    vis[p.ff][p.ss]=1;
    while(!pq.empty()){
        auto [x,y]=pq.front();
        pq.pop();
        for(int k=0; k<4; k++){
            int i=x+dx[k];
            int j=y+dy[k];
            if(i<0 || j<0 || i>=n || j>=m){continue;}
            if(!vis[i][j] && v[i][j]!='#'){
                vis[i][j]=1;
                pq.push({i,j});
                if(v[i][j]=='V'){ans++;}
            }
        }
    }
    return -(10*ans);
}


int bfs(vector<vector<char>>&v){
    vector<vector<int>>cost(n,vector<int>(m,1e9));
    cost[f.ff][f.ss]=0;
    queue<tuple<int,int,int>>pq;
    pq.push({0,f.ff, f.ss});
    while(!pq.empty()){
        auto [d,x,y]=pq.front();
        pq.pop();
        d++;
        for(int k=0; k<4; k++){
            int i=x+dx[k];
            int j=y+dy[k];
            if(i<0 || j<0 || i>=n || j>=m){continue;}
            if(cost[i][j]>d && v[i][j]!='#'){
                cost[i][j]=d;
                pq.push({d,i,j});
            }
        }
    }

    int reaching_food_time=cost[p.ff][p.ss];
    if(reaching_food_time==1e9){
       return not_connected(v);
    }
    int ans=500;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]=='V' && cost[i][j]<=reaching_food_time){
                ans-=10;
            }
        }
    }
    return ans;
}


void solve(int T){
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]=='P'){p={i,j};}
            if(v[i][j]=='F'){f={i,j};}
        }
    }
    int ans=bfs(v);
    cout<<ans<<endl;
}



//DRINK WATER
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