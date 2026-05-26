#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;
//using i128 = __int128_t;

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
const int N=2e5+7;
map<char,int>ans;
bool ses=0;

void cal(map<char,int>&mp){
    if(mp['S']==1){
        ans[mp['x']]=mp['v'];
        ans['P']++;
    }
    else if(mp['S']==2){
        ans[mp['x']]++;
        ans['P']++;
    }
    else if(mp['S']==3){
        ans[mp['x']]+=ans[mp['y']];
        ans['P']++;
    }
    else if(mp['S']==4){
        ans[mp['x']]*=ans[mp['y']];
        ans['P']++;
    }
    else if(mp['S']==5){
        ans['P']=mp['v'];
    }
    else if(mp['S']==6){
        if(ans[mp['x']]==ans[mp['y']]){ans['C']=0;}
        else if(ans[mp['x']]>ans[mp['y']]){ans['C']=1;}
        else{ans['C']=-1;}
        ans['P']++;
    }
    else if(mp['S']==7){
        if(ans['C']==0){
            ans['P']=mp['v'];
        }
        else{
            ans['P']++;
        }
    }
    else if(mp['S']==8){
        if(ans['C']>0){
            ans['P']=mp['v'];
        }
        else{
            ans['P']++;
        }
    }
    else if(mp['S']==9){
        if(ans['C']<0){
            ans['P']=mp['v'];
        }
        else{
            ans['P']++;
        }
    }
    else if(mp['S']==10){
        ses=1;
    }
}


void solve(int T){
    vector<map<char,int>>vv;

    string s;
    while(cin>>s){
        map<char,int>mp;
        char x,y;   int v;
        if(s=="LOD"){
            mp['S']=1;
            cin>>x>>v;
            mp['x']=x;
            mp['v']=v;
        }
        else if(s=="INC"){
            mp['S']=2;
            cin>>x;
            mp['x']=x;
        }
        else if(s=="ADD"){
            mp['S']=3;
            cin>>x;
            mp['x']=x;
            cin>>y;
            mp['y']=y;
        }
        else if(s=="MUL"){
            mp['S']=4;
            cin>>x;
            mp['x']=x;
            cin>>y;
            mp['y']=y;
        }
        else if(s=="JMP"){
            mp['S']=5;
            cin>>v;
            mp['v']=v;
        }
        else if(s=="CMP"){
            mp['S']=6;
            cin>>x;
            mp['x']=x;
            cin>>y;
            mp['y']=y;
        }
        else if(s=="JCZ"){
            mp['S']=7;
            cin>>v;
            mp['v']=v;
        }
        else if(s=="JCP"){
            mp['S']=8;
            cin>>v;
            mp['v']=v;
        }
        else if(s=="JCN"){
            mp['S']=9;
            cin>>v;
            mp['v']=v;
        }
        else{mp['S']=10;}
        vv.pb(mp);
    }
    
    while(ans['P']<vv.size()){
        if(ses){break;}
        cal(vv[ans['P']]);
    }

    cout<<ans['A']<<" ";
    cout<<ans['B']<<" ";
    cout<<ans['C']<<" ";
    cout<<ans['D']<<" ";
    cout<<ans['E']<<" ";
    cout<<ans['F']<<" ";
    cout<<ans['P']<<endl;
} 



    

int32_t main(){             //DRINK WATER
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

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/
