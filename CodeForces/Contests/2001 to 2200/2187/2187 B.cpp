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
// const int N=1e6+7;

int X,Y;
int ans=LLMax;
int PPP,QQQ;

void fff(int x, int y, int p, int q, int i, bool last_a, bool last_b, int changed){
    if(i<0){
        int temp=abs(X-p)+abs(Y-q);
        if(temp<ans && (p&q)==0){
            ans=temp;
            PPP=p;
            QQQ=q;
        }
        return;
    }
    int a=(x>>i)&1;
    int b=(y>>i)&1;

    if(a==0 && b==0){
        fff(x,y,p,q,i-1,0,0,changed);

    }
    else if(a==1 && b==0){
        fff(x,y,p^(1<<i),q,i-1,1,0,changed);
        if(last_a==0 && last_b==0){
            fff(0,y, p^(1<<(i+1)), q,i-1, 0,0,changed);
        }
    }
    else if(a==0 && b==1){
        fff(x,y,p,q^(1<<i),i-1,0,1,changed);
        if(last_a==0 && last_b==0){
            fff(x,0, p, q^(1<<(i+1)),i-1, 0,0,changed);
        }
    }
    else{
        if(changed==1){
            fff(x,(1<<i)-1,p^(1<<i),q,i-1,1,0,changed);
        }
        else{
            fff((1<<i)-1,y,p,q^(1<<i),i-1,0,1,changed);
        }
        if(last_a==0 && last_b==0){
            fff(x,0, p^(1<<i), q^(1<<(i+1)),i-1, 1,0,changed);
            fff(0,y, p^(1<<(i+1)), q^(1<<i),i-1, 0,1,changed);
        }
    }

}

void solve(int T){
    cin>>X>>Y;
    ans=LLMax;
    fff(X,Y,0,0,30,0,0,0);
    fff(X,Y,0,0,30,0,0,1);
    cout<<PPP<<" "<<QQQ<<endl;
    //cout<<abs(X-PPP)+abs(Y-QQQ)<<endl;
} 



    

int32_t main(){             //DRINK WATER
    //war();
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