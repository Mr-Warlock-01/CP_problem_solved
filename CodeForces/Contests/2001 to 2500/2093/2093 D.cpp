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

#define int ll

int f1(int x,int y, int n){
    if(n==2){
        if(x==y){return x;}
        if(x>y){return 3;}
        return 4;
    }
    int nn=n/2;
    if(x<=nn && y<=nn)return f1(x,y,nn);
    if(x>nn && y>nn){return f1(x-nn,y-nn,nn)+(nn*nn);}
    if(x>nn && y<=nn){return f1(x-nn,y,nn)+(2*nn*nn);}
    return f1(x,y-nn,nn)+(3*nn*nn);
}


pair<int,int>f2(int d, int n){
    if(n==1){
        if(d==1){return {1,1};}
        if(d==2){return {2,2};}
        if(d==3){return {2,1};}
        return {1,2};
    }
    int nn=n/2;
    nn*=nn;
    if(d<=nn){return f2(d,n/2);}
    if(d<=(2*nn)){
        auto z=f2(d-nn,n/2);
        z.ff+=n/2;
        z.ss+=n/2;
        return z;
    }
    if(d<=(3*nn)){
        auto z=f2(d-(2*nn),n/2);
        z.ff+=n/2;
        return z;
    }
    auto z=f2(d-(3*nn),n/2);
    z.ss+=n/2;
    return z;
}

 
void solve(int T){            ///   (DRINK WATER)
    int n;  cin>>n;
    int nn=1<<n;
    int q;  cin>>q;
    while(q--){
        char c; cin>>c>>c;
        if(c=='>'){
            int x,y;    cin>>x>>y;
            cout<<f1(x,y,nn)<<endl;

        }
        else{
            int d;  cin>>d;
            auto z=f2(d,nn);
            cout<<z.ff<<" "<<z.ss<<endl;
        }
    }
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