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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define int ll

const int N=2502;

struct BIT2D{
    int BIT[N][N];

    int query(int x, int y){
        int ans=0;
        int xx=x;
        while(xx!=0){
            int yy=y;
            while(yy!=0){
                ans+=BIT[xx][yy];
                yy-=(yy&(-yy));
            }
            xx-=(xx&(-xx));
        }
        return ans;
    }

    void update(int x, int y, int val){
        int xx=x;
        while(xx<N){
            int yy=y;
            while(yy<N){
                BIT[xx][yy]+=val;
                yy+=(yy&(-yy));
            }
            xx+=(xx&(-xx));
        }
    }

    void update_range(int x1 ,int y1, int  x2, int y2, int val){
        update(x1, y1, val);
        update(x2+1, y1, -val);
        update(x1, y2+1, -val);
        update(x2+1, y2+1, val);
    }

    int point_query(int x ,int y){
        return query(x,y) - query(x,y-1) -query(x-1,y) +query(x-1,y-1);
    }
};



void solve(int T){
    int n,m,q;  cin>>n>>m>>q;
    BIT2D tree1, tree2;
    map<tuple<int,int,int,int>,int>mp1, mp2;
    while(q--){
        int type, x1, y1, x2, y2;   cin>>type>>x1>>y1>>x2>>y2;
        if(type==1){
            int z1=rnd();
            int z2=rnd();
            mp1[{x1, y1, x2, y2}]=z1;
            mp2[{x1, y1, x2, y2}]=z2;
            tree1.update_range(x1,y1, x2, y2, z1);
            tree2.update_range(x1,y1, x2, y2, z2);
        }
        else if(type==2){
            int z1=mp1[{x1, y1, x2, y2}];
            int z2=mp2[{x1, y1, x2, y2}];
            tree1.update_range(x1,y1, x2, y2, -z1);
            tree2.update_range(x1,y1, x2, y2, -z2);
        }
        else{
            int xxx1=tree1.query(x1,y1);
            int xxx2=tree2.query(x1,y1);
            int xxx3=tree1.query(x2,y2);
            int xxx4=tree2.query(x2,y2);
            if(xxx1==xxx3 && xxx2==xxx4){
                YES;
            }
            else{NO;}
        }
    }

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