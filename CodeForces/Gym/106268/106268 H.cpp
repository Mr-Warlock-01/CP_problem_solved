#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
using u128 = __uint128_t;

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
const ll MOD   = 1e9+7;
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

#define YES {cout<<"yes"<<endl;}
#define NO  {cout<<"no"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN ODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

#define int ll
const int N=1009;

char arr[N][N];

vector<pair<int,int>>c1,c2,c3,c4;
int n,m,k;  

void gen_ok(int k){
    c1.clear();
    c2.clear();
    c3.clear();
    c4.clear();

    for(int i=0; i<k; i++){
        c1.pb({0,i});
        c1.pb({i,0});
        c1.pb({k-1,i});
    }

    for(int i=0; i<k; i++){
        c2.pb({i,0});
        c2.pb({i,k-1});
        c2.pb({0,i});
    }

    for(int i=0; i<k; i++){
        c3.pb({0,i});
        c3.pb({k-1,i});
        c3.pb({i,k-1});
    }

    for(int i=0; i<k; i++){
        c4.pb({k-1,i});
        c4.pb({i,0});
        c4.pb({i,k-1});
    }
}


bool check_c1(int x, int y){
    for(auto [a,b]:c1){
        int xx=x+a;
        int yy=y+b;
        if(xx>n & yy>m){return 0;}
        if(arr[xx][yy]!='#'){return 0;}
    }
    return 1;
}

bool check_c2(int x, int y){
    for(auto [a,b]:c2){
        int xx=x+a;
        int yy=y+b;
        if(xx>n & yy>m){return 0;}
        if(arr[xx][yy]!='#'){return 0;}
    }
    return 1;
}

bool check_c3(int x, int y){
    for(auto [a,b]:c3){
        int xx=x+a;
        int yy=y+b;
        if(xx>n & yy>m){return 0;}
        if(arr[xx][yy]!='#'){return 0;}
    }
    return 1;
}

bool check_c4(int x, int y){
    for(auto [a,b]:c4){
        int xx=x+a;
        int yy=y+b;
        if(xx>n & yy>m){return 0;}
        if(arr[xx][yy]!='#'){return 0;}
    }
    return 1;
}

void solve(int T){
    cin>>n>>m>>k;

    gen_ok(k);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j]=='#'){
                if(check_c1(i,j)){
                for(auto [a,b]:c1){
                    int xx=i+a;
                    int yy=j+b;
                    arr[xx][yy]='.';
                }
            }
            else if(check_c2(i,j)){
                for(auto [a,b]:c2){
                    int xx=i+a;
                    int yy=j+b;
                    arr[xx][yy]='.';
                }
            }
            else if(check_c3(i,j)){
                for(auto [a,b]:c3){
                    int xx=i+a;
                    int yy=j+b;
                    arr[xx][yy]='.';
                }
            }
            else if(check_c4(i,j)){
                for(auto [a,b]:c4){
                    int xx=i+a;
                    int yy=j+b;
                    arr[xx][yy]='.';
                }
            }
            else{  NO; return;}
            }
        }
    }
    YES;
} 



    

int32_t main(){             //DRINK WATER
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

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/
 