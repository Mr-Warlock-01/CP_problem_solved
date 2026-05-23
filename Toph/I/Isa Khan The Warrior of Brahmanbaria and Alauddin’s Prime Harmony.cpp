// https://toph.co/arena?practice=68684fc95765c6a7101c4e2f#!/p/6863ca4db4ab47db2729d4e5

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
const int N=3e4+2;
vector<int>prime;
 
void prime_gen(){
    bitset<N>p;
    p.set();
    p[0]=p[1]=0;
    prime.pb(2);
    for(ll i=3; i<N; i+=2){
        if(p[i]==1){
            prime.pb(i);
            for(ll j=i*i; j<N; j+=(2*i)){p[j]=0;}
        }
    }
}

void solve(int T){

    int A,B,c;  cin>>A>>B>>c;
    vector<int>ans;
    prime_gen();
    set<int>s;
    for(int i=1; i<prime.size()-1; i++){
        if(prime[i]*2==(prime[i-1]+prime[i+1])){
            s.insert(prime[i]);
        }
    }
    if(A!=0){
        for(int i=c; i<=10000; i++){
            if(s.find(i)==s.end()){continue;}
            int C=i-c;
            u128 z=((u128)B*(u128)B) + ((u128)4*(u128)A*(u128)C);
            if(z<0){continue;}
            u128 ok=sqrtl(z);
            if((u128)z!=((u128)ok*(u128)ok)){continue;}
            ok-=(u128)B;
            if((ok%(2*(u128)A))!=0){continue;}
            ans.pb(i);
        }
        int sz=ans.size();
        if(sz==0){sz=-1;}
        cout<<sz<<endl;
        for(int i=0; i<sz; i++){
            cout<<ans[i]<<" ";
        } 
    }
    else{
        if(B==0){cout<<"-1"<<endl; return;}
        for(int i=c; i<=10000; i++){
            if(s.find(i)==s.end()){continue;}
            int C=i-c;
            if(C%B){continue;}
            ans.pb(i);
        }

        int sz=ans.size();
        if(sz==0){sz=-1;}
        cout<<sz<<endl;
        for(int i=0; i<sz; i++){
            cout<<ans[i]<<" ";
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