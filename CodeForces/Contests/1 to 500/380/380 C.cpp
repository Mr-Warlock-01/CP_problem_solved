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
//#define int ll
const int N=1e6+3;

string s;
pair<int,pair<int,int>>treee[4*N]; //ans, ( , ) 

void build(int node, int st, int en){
    if(st==en){
        if(s[st]=='('){treee[node].ss.ff=1;}
        else{treee[node].ss.ss=1;}
        return;
    }
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);

    int new_add=min(treee[2*node].ss.ff,treee[2*node+1].ss.ss);
    treee[node].ff = treee[2*node].ff+treee[2*node+1].ff +(2*new_add);
    treee[node].ss.ff=treee[2*node].ss.ff+treee[2*node+1].ss.ff-new_add;
    treee[node].ss.ss=treee[2*node].ss.ss+treee[2*node+1].ss.ss-new_add;
    return;
}

pair<int,pair<int,int>> query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return {0,{0,0}};}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    pair<int,pair<int,int>>q1= query(2*node, st, mid, l, r);
    pair<int,pair<int,int>>q2= query(2*node+1, mid+ 1, en, l, r);

    int new_add=min(q1.ss.ff,q2.ss.ss);
    int ans=q1.ff+q2.ff +(2*new_add);
    int opening=q1.ss.ff+q2.ss.ff-new_add;
    int closing=q1.ss.ss+q2.ss.ss-new_add;
    return {ans,{opening,closing}};
}




void solve(int T){
    cin>>s;
    int n=s.size();
    build(1,0,n-1);

    int q;  cin>>q;
    while(q--){
        int l,r;    cin>>l>>r;  l--; r--;
        int ans=query(1, 0, n-1, l, r).ff;
        cout<<ans<<endl;
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