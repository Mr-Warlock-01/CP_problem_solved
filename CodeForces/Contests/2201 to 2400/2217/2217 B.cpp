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
const int N=2e5+9;

bool arr[N];
set<int>s;
int n,k;




bool middle(int l,int r){
    auto it=s.lower_bound(l);
    return (*it<=r);
}

int xxx_left(int idx, int f){
    for(int i=idx; i<=n; i++){
        if(arr[i]==f){return i;}
    }
    return n+1;
}

int xxx_right(int idx, int f){
    for(int i=idx; i>0; i--){
        if(arr[i]==f){return i;}
    }
    return 0;
}


int find_ans(){
    int l=1, r=n;
    int f=0;
    int ans=0;
    while(l<=r){
        int Lef=xxx_left(l,f);
        int Rig=xxx_right(r,f);
        if(Lef>Rig){
            l=Lef;
            r=Rig;
            break;
        }
        bool middle_a_ase=middle(Lef,Rig);
        if(!middle_a_ase){
            l=Lef;
            r=Rig;
            break;
        }
        ans++;
        f^=1;
        l=Lef+1;
        r=Rig-1;
    }

    db(ans)
    if(l>r){return ans;}
    int a1,a2;
    for(auto u:s){
        if(u<l){a1=u;}
        if(u>r){a2=u; break;}
    }
    
    bool z1=f;int cnt1=0;
    if(a2<=n){
        for(int i=l; i<a2; i++){
        if(arr[i]==z1){
            cnt1++;
           z1^=1;  
        }
    }
    }
    else{
        cnt1=LLMax;
    }
    bool z2=f;int cnt2=0;
    if(a1>0){
        for(int i=r; i>a1; i--){
        if(arr[i]==z2){
            cnt2++;
            z2^=1;
        }
    }
    }
    if(a1<=0){
        cnt2=LLMax;
    }
    if(a2>n){
        cnt1=LLMax;
    }
    db(cnt1);
    db(cnt2)
    if(cnt1%2==1){cnt1++;}
    if(cnt2%2==1){cnt2++;}
    return ans+min(cnt1,cnt2);

}



void solve(int T){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    s.clear();
    s.insert(-1e9);
    s.insert(1e9);
    bool c=0;
    for(int i=0; i<k; i++){
        int a;  cin>>a;
        s.insert(a);
        if(arr[a]==0){c=1;}
    }

    if(c){
        for(int i=1; i<=n; i++){
            arr[i]^=1;
        }
    }
    int ans=find_ans();
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