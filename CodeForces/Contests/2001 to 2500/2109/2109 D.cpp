#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
using u128 = __uint128_t;
 
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
#define int ll

const int N=2e5+90;


vector<int>graph[N];
int cost[2][N];
bool ans[N];
vector<int>odd_num;
vector<int>even_num;
int even,odd;

void dijkastra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,1});
    cost[0][1]=0;
    while(!pq.empty()){
        int dis=pq.top().ff;
        int node=pq.top().ss;
        int new_dis=dis+1;
        pq.pop();

        if(dis%2==0 && dis!=cost[0][node]){continue;}
        if(dis%2==1 && dis!=cost[1][node]){continue;}

        if(new_dis%2==0){
            for(auto u: graph[node]){
                if(cost[0][u]>new_dis){
                    cost[0][u]=new_dis;
                    pq.push({new_dis,u});
                }
            }
        }
        else{
            for(auto u: graph[node]){
                if(cost[1][u]>new_dis){
                    cost[1][u]=new_dis;
                    pq.push({new_dis,u});
                }
            }
        }
    }
}




void clear_kori(int n){
    even=0, odd=0;
    for(int i=0; i<=n; i++){
        graph[i].clear();
        cost[0][i]=10000000000000;
        cost[1][i]=10000000000001;
        ans[i]=0;
    }
    even_num.clear();
    odd_num.clear();

}
 
void solve(int T){
    int n,m,l;  cin>>n>>m>>l;
    
    clear_kori(n+5);

    for(int i=0; i<l; i++){
        int a;  cin>>a;
        if(a%2==0){even_num.pb(a);}
        else{odd_num.pb(a);}
    }

    sort(rall(odd_num));

    for(int i=0; i<even_num.size(); i++){
        even+=even_num[i];
    }
    if(odd_num.size()>0){odd=odd_num[0];}

    for(int i=2; i<odd_num.size(); i+=2){
        odd+=odd_num[i-1]+odd_num[i];
    }
    if(odd!=0){odd+=even;}

    for(int i=1; i<odd_num.size(); i+=2){
        even+=odd_num[i-1]+odd_num[i];
    }




    

    for(int i=0; i<m; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dijkastra();

    for(int i=1; i<=n; i++){
        if(even>=cost[0][i]){ans[i]=1;}
        else if(odd>=cost[1][i]){ans[i]=1;}
    }

    for(int i=1; i<=n; i++){cout<<ans[i];}
    cout<<endl;

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