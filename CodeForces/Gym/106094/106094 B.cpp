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

const int N=2e5+7;
int ANS[N];
pair<int,int>v[N];
int pre_sum[N];

void solve(int T){
    int n;  cin>>n;
    int time;   cin>>time;
    for(int i=1; i<=n; i++){
        cin>>v[i].ff;
        v[i].ss=i;
    }
    sort(v+1, v+n+1);
    pre_sum[0]=0;
    for(int i=1; i<=n; i++){
        pre_sum[i]=pre_sum[i-1]+v[i].ff;
    }

    int ans=0;
    int aaa=-1, bbb=-1;

    for(int i=0; i<=n; i++){
        int points=0;
        int temp_b=0;
        int l=0, r=n-i;
        while(l<=r){
            int mid=(l+r)/2;
            int twox=n-i-mid;
            
            int ttt=pre_sum[i];
            ttt+= (((pre_sum[i+mid] - pre_sum[i])*2)/3);
            ttt+= (pre_sum[n] - pre_sum[i+mid])/2;

            int temp_point=(i*100) + (mid* 75) + ((n-i-mid)*50);
            if(ttt<=time){
                temp_b=mid;
                l=mid+1;
                points=temp_point;
            }
            else{
                r=mid-1;
            }
        }
        if(points>ans){
            ans=points;
            aaa=i;
            bbb=temp_b;
        }
    }

    db(aaa) db(bbb)

    for(int i=1; i<=aaa; i++){
        ANS[v[i].ss]=1;
    }
    for(int i=aaa+1; i<=(aaa+bbb); i++){
        ANS[v[i].ss]=-1;
    }
    for(int i=aaa+bbb+1; i<=n; i++){
        ANS[v[i].ss]=2;
    } 
    cout<<ans<<endl;
    for(int i=1; i<=n; i++){
        if(ANS[i]==-1){
            cout<<"1.5 ";
        }
        else{
            cout<<ANS[i]<<" ";
        }

    }cout<<endl;
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