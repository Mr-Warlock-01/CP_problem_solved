#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
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

// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x){
//         x+=0x9e3779b97f4a7c15;  x=(x^(x>>30))*0xbf58476d1ce4e5b9;   x=(x^(x>>27))*0x94d049bb133111eb;
//         return x^(x>>31);
//     }
//     size_t operator()(uint64_t x) const{
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
//     size_t operator()(pair<uint64_t, uint64_t>x) const { 
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); 
//         return splitmix64(x.first+FIXED_RANDOM)^(splitmix64(x.second+FIXED_RANDOM)>>1); 
//     }
    
// };

#define int ll
const int N=2e5+7;


void solve(int T){
    int n;  cin>>n;
    vector<int>v(n);    cin>>v; 
    map<int, int>mp[n];
    map<int, int>track;

    for(int i=0; i<n; i++){
        if(i==0){
            int cnt=0;
            track[v[i]]++;
            mp[i][v[i]]=0;
            while(v[i]!=1){
                if(v[i]%2==0){v[i]/=2;}
                else{v[i]++;}
                cnt++;
                track[v[i]]++;
                mp[i][v[i]]=cnt;
            }   
            if(mp[i].find(2)==mp[i].end()){
                mp[i][2]=cnt+1;
                track[2]++;
            }
        }
        else{
            int cnt=0;
            if(track.find(v[i])!=track.end()){
                track[v[i]]++;
                mp[i][v[i]]=0;
            }
            while(v[i]!=1){
                if(v[i]%2==0){v[i]/=2;}
                else{v[i]++;}
                cnt++;
                if(track.find(v[i])!=track.end()){
                    track[v[i]]++;
                    mp[i][v[i]]=cnt;
                }
            }   
            if(mp[i].find(2)==mp[i].end()){
                if(track.find(v[i])!=track.end()){
                   mp[i][2]=cnt+1;
                    track[2]++;
                }
            }
        }
    }

    int ans=LLMax;
    for(auto [u,v]: track){
        if(v==n){
            int temp=0;
            for(int i=0; i<n; i++){
                temp+=mp[i][u];
            }
            ans=min(ans,temp);
        }
    }
    cout<<ans<<endl;
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