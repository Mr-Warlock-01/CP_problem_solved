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

#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

#define int ll

const int N=1005;
char arr[N][N];
int cost[N][N];
int n,m;    
int a,b,c,d;    

// int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
// int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};

bool node(int x, int y){
    if(x<0 || y<0){return 0;}
    if(x>=n || y>=m){return 0;}
    return 1;
}

int dijkastra(){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    //weight,node
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cost[i][j]=1e8;
        }
    }
    pq.push({0,{a,b}});
    cost[a][b]=0;
    while(!pq.empty()){
        int dis=pq.top().ff;
        int xx=pq.top().ss.ff;
        int yy=pq.top().ss.ss;
        if(c==xx && d==yy){return dis;}
        pq.pop();
        if(dis!=cost[xx][yy]){continue;}

        for(int i=0; i<4; i++){
            int new_x=xx+dx[i];
            int new_y=yy+dy[i];

            if(node(new_x, new_y) && arr[new_x][new_y]=='.' && cost[new_x][new_y]>dis){
                pq.push({dis, {new_x, new_y}});
                cost[new_x][new_y]=dis;
            }
            else if(node(new_x, new_y) && arr[new_x][new_y]=='#' && cost[new_x][new_y]>(dis+1)){
                pq.push({dis+1, {new_x, new_y}});
                cost[new_x][new_y]=dis+1;
                new_x+=dx[i];
                new_y+=dy[i];
                if(node(new_x, new_y) && cost[new_x][new_y]>(dis+1)){
                    pq.push({dis+1, {new_x, new_y}});
                    cost[new_x][new_y]=dis+1;
                }
            } 
            else if(node(new_x, new_y) && arr[new_x][new_y]=='#' && cost[new_x][new_y]==(dis+1)){
                new_x+=dx[i];
                new_y+=dy[i];
                if(node(new_x, new_y) && cost[new_x][new_y]>(dis+1)){
                    pq.push({dis+1, {new_x, new_y}});
                    cost[new_x][new_y]=dis+1;
                }
            } 

        }
    }
    return 0;
}


void solve(int T){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cin>>a>>b>>c>>d;
    a--; b--; c--; d--;

    cout<<dijkastra();
}




//DRINK WATER
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