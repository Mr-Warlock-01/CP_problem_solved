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
const int N=1e6+7;

struct triangle{
    int x1,x2,x3,y1,y2,y3;

};

vector<triangle>v;

void gen_3(){
    triangle tt;
    tt.x1=1; tt.y1=1;
    tt.x2=1; tt.y2=2;
    tt.x3=2; tt.y3=3;
    v.pb(tt);   //1

    tt.x1=2; tt.y1=1;
    tt.x2=2; tt.y2=2;
    tt.x3=3; tt.y3=3;
    v.pb(tt);   //2

    tt.x1=3; tt.y1=1;
    tt.x2=3; tt.y2=2;
    tt.x3=4; tt.y3=3;
    v.pb(tt);   //3

    tt.x1=4; tt.y1=1;
    tt.x2=4; tt.y2=2;
    tt.x3=5; tt.y3=3;
    v.pb(tt);   //4

    tt.x1=5; tt.y1=1;
    tt.x2=5; tt.y2=2;
    tt.x3=6; tt.y3=3;
    v.pb(tt);   //5

    tt.x1=6; tt.y1=1;
    tt.x2=6; tt.y2=2;
    tt.x3=7; tt.y3=3;
    v.pb(tt);   //6

    tt.x1=7; tt.y1=1;
    tt.x2=7; tt.y2=2;
    tt.x3=8; tt.y3=3;
    v.pb(tt);   //7

    tt.x1=8; tt.y1=1;
    tt.x2=8; tt.y2=2;
    tt.x3=9; tt.y3=1;
    v.pb(tt);   //8

    tt.x1=9; tt.y1=4;
    tt.x2=9; tt.y2=5;
    tt.x3=8; tt.y3=5;
    v.pb(tt);   //9

    tt.x1=7; tt.y1=4;
    tt.x2=7; tt.y2=5;
    tt.x3=8; tt.y3=6;
    v.pb(tt);   //10

    tt.x1=6; tt.y1=4;
    tt.x2=6; tt.y2=5;
    tt.x3=5; tt.y3=5;
    v.pb(tt);   //11

    tt.x1=9; tt.y1=2;
    tt.x2=9; tt.y2=3;
    tt.x3=8; tt.y3=4;
    v.pb(tt);   //12

    tt.x1=8; tt.y1=8;
    tt.x2=9; tt.y2=9;
    tt.x3=9; tt.y3=8;
    v.pb(tt);   //13

    tt.x1=7; tt.y1=8;
    tt.x2=7; tt.y2=9;
    tt.x3=8; tt.y3=9;
    v.pb(tt);   //14

    tt.x1=8; tt.y1=7;
    tt.x2=9; tt.y2=7;
    tt.x3=9; tt.y3=6;
    v.pb(tt);   //15

    tt.x1=6; tt.y1=8;
    tt.x2=6; tt.y2=9;
    tt.x3=5; tt.y3=9;
    v.pb(tt);   //16

    tt.x1=4; tt.y1=8;
    tt.x2=4; tt.y2=9;
    tt.x3=3; tt.y3=9;
    v.pb(tt);   //17

    tt.x1=3; tt.y1=8;
    tt.x2=2; tt.y2=9;
    tt.x3=1; tt.y3=9;
    v.pb(tt);   //18

    tt.x1=7; tt.y1=6;
    tt.x2=7; tt.y2=7;
    tt.x3=6; tt.y3=7;
    v.pb(tt);   //19

    tt.x1=4; tt.y1=4;
    tt.x2=4; tt.y2=5;
    tt.x3=5; tt.y3=4;
    v.pb(tt);   //20

    tt.x1=1; tt.y1=3;
    tt.x2=1; tt.y2=4;
    tt.x3=2; tt.y3=5;
    v.pb(tt);   //21

    tt.x1=2; tt.y1=4;
    tt.x2=3; tt.y2=4;
    tt.x3=3; tt.y3=5;
    v.pb(tt);   //22

    tt.x1=5; tt.y1=6;
    tt.x2=6; tt.y2=6;
    tt.x3=5; tt.y3=7;
    v.pb(tt);   //23

    tt.x1=4; tt.y1=6;
    tt.x2=4; tt.y2=7;
    tt.x3=5; tt.y3=8;
    v.pb(tt);   //24

    tt.x1=2; tt.y1=6;
    tt.x2=3; tt.y2=6;
    tt.x3=3; tt.y3=7;
    v.pb(tt);   //25

    tt.x1=1; tt.y1=5;
    tt.x2=1; tt.y2=6;
    tt.x3=2; tt.y3=7;
    v.pb(tt);   //26

    tt.x1=1; tt.y1=7;
    tt.x2=1; tt.y2=8;
    tt.x3=2; tt.y3=8;
    v.pb(tt);   //27
}

vector<triangle>xxx(int n, int m){
    if(n==m && n==9){return v;}
    vector<triangle>ans;
    for(int i=1; i<=n; i+=2){
        for(int j=1; j<=m; j+=3){
            triangle tt;
            tt.x1=i;   tt.y1=j;
            tt.x2=i+1; tt.y2=j;
            tt.x3=i+1; tt.y3=j+1;
            ans.pb(tt);

            tt.x1=i;   tt.y1=j+1;
            tt.x2=i;   tt.y2=j+2;
            tt.x3=i+1; tt.y3=j+2;
            ans.pb(tt);
        }
    }
    return ans;
}


void solve(int T){
    int n;  cin>>n;
    vector<triangle>ans;
    if(n==1){
        cout<<"2"<<endl;
        cout<<"1 1 1 2 2 1"<<endl;
        cout<<"2 3 3 2 3 3"<<endl;
        return;
    }
    if(n%2==0){
        ans=xxx(3*n,3*n);
    }
    else{
        ans=xxx(9,9);
        vector<triangle>temp=xxx((3*n)-9,9);

        for(auto u:temp){
            triangle t=u;
            
            t.x1+=9;
            t.x2+=9;
            t.x3+=9;
            ans.pb(t);

            t=u;
            swap(t.x1,t.y1);
            swap(t.x2,t.y2);
            swap(t.x3,t.y3);
            t.y1+=9;
            t.y2+=9;
            t.y3+=9;
            ans.pb(t);
        }
        temp=xxx((3*n)-9,(3*n)-9);
        for(auto u:temp){
            triangle t=u;
            t.x1+=9;    t.y1+=9;
            t.x2+=9;    t.y2+=9;
            t.x3+=9;    t.y3+=9;
            ans.pb(t);
        }



    }
    cout<<3*n*n<<endl;
    for(auto u:ans){
        cout<<u.x1<<" "<<u.y1<<" ";
        cout<<u.x2<<" "<<u.y2<<" ";
        cout<<u.x3<<" "<<u.y3<<endl;
    }
}   




    

int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////
    gen_3();
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