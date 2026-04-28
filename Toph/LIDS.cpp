// https://toph.co/p/lids

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
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


string s1,s2;
int max_len=0;
int dp1[13][13][2][2][2]; //pos, last, low, up, started
int dp2[13][13][2][2][2][10]; //pos, last, low, up, started

//taking impossible case as 0 instead of -1, and taking 0-9 ans 1-10

int cal_len(int pos, int last, bool low, bool up, bool start){
    if(pos==13){return 0;}
    if(dp1[pos][last][low][up][start]!=-1){return dp1[pos][last][low][up][start];}

    int st=1, en=10;
    if(low==1){st=s1[pos]-'0'+1;}
    if(up==1){en=s2[pos]-'0'+1;}

    int ans=LLMin;
    if(st==en){
        ans=max(ans, cal_len(pos+1, last, low, up, start|(st!=1)));
        if((last<st) && ((start|(st!=1))==1)){
            ans=max(ans,cal_len(pos+1, st, low, up, 1)+1);
        }
    }
    else{
        ans=max(ans, cal_len(pos+1, last, low, 0, start|(st!=1)));
        if((last<st) && ((start|(st!=1))==1)){
            ans=max(ans, cal_len(pos+1, st, low, 0, 1)+1);
        }
        for(int i=st+1; i<en; i++){
            ans=max(ans, cal_len(pos+1, last, 0, 0, 1));
            if(last<i){
                ans=max(ans, cal_len(pos+1, i, 0, 0, 1)+1);
            }
        }
        ans=max(ans, cal_len(pos+1, last, 0, up, 1));
        if(last<en){
            ans=max(ans, cal_len(pos+1, en, 0, up, 1)+1);
        }
    }
    return dp1[pos][last][low][up][start]=ans;
}


int cnt(int pos, int last, bool low, bool up, bool start, int len){
    if(pos==13){
        if(len==max_len){return 1;}
        return 0;
    }
    if(dp2[pos][last][low][up][start][len]!=-1){return dp2[pos][last][low][up][start][len];}

    int st=1, en=10;
    if(low==1){st=s1[pos]-'0'+1;}
    if(up==1){en=s2[pos]-'0'+1;}

    int ans=0;

    if(st==en){
        ans+=cnt(pos+1, last, low, up, start|(st!=1), len);
        if((last<st) && ((start|(st!=1))==1)){
            ans+=cnt(pos+1, st, low, up, 1,len+1);
        }
    }
    else{
        ans+=cnt(pos+1, last, low, 0, start|(st!=1), len);
        if((last<st) && ((start|(st!=1))==1)){
            ans+=cnt(pos+1, st, low, 0, 1, len+1);
        }
        for(int i=st+1; i<en; i++){
            ans+=cnt(pos+1, last, 0, 0, 1, len);
            if(last<i){
                ans+=cnt(pos+1, i, 0, 0, 1, len+1);
            }
        }
        ans+=cnt(pos+1, last, 0, up, 1,len);
        if(last<en){
            ans+=cnt(pos+1, en, 0, up, 1, len+1);
        }
    }

    return dp2[pos][last][low][up][start][len]=ans;
}








void solve(int T){
    int x,y;    cin>>x>>y;
    s1=""; s2="";

    for(int i=0; i<13; i++){
        int z=x%10;
        x/=10;
        s1.pb(z+'0');
        z=y%10;
        y/=10;
        s2.pb(z+'0');
    }

    reverse(all(s1));
    reverse(all(s2));
    int sz=s1.size();

    //clear
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    max_len=0;

    max_len=cal_len(0, 0, 1, 1, 0);

    int ans=cnt(0,0,1,1,0,0);
    cout<<"Case "<<T<<": ";
    cout<<max_len<<" "<<ans<<endl;
    

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
