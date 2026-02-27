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
// *.find_by_order(x)
//substr
//cin.ignore();
//get<idx>(z) //tuple
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

ll gcd(ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}
ll lcm(ll a, ll b){return ((a/gcd(a,b))*b);}

//#define int ll
const int N=1e5+7;
vector<int>factor[5003];
int arr[N];
int treee[50][4*N];

void find_all_factor(){
    stack<int>st;
    //int mx=0;
    for(int i=1; i<=5000; i++){
        for(int j=1; (j*j)<=i; j++){
            if(i%j==0){
                factor[i].pb(j);
                if(j!=(i/j)){st.push(i/j);}
            }
        }
        while(!st.empty()){
            factor[i].pb(st.top());
            st.pop();
        }
        //mx=max(mx, (int)(factor[i].size()));
    }
    //db(mx);
}

void build(int node, int st, int en, int idx, int M){
    if(st==en){treee[idx][node]=((arr[st]%M)!=0); return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid, idx, M);
    build(2*node+1, mid+1, en, idx, M);
    treee[idx][node]=treee[idx][2*node]+treee[idx][2*node+1];
    return;
}

int query(int node, int st, int en, int l, int r, int idx){
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return treee[idx][node];}
    int mid=((en-st)/2)+st;
    int q1= query(2*node, st, mid, l, r, idx);
    int q2= query(2*node+1, mid+ 1, en, l, r, idx);
    return q1+q2;
}

void update(int node, int st, int en, int ind, int idx){
    if(st==en){treee[idx][node]^=1;   return;}
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){update(2*node,st, mid, ind, idx);}
    else{update(2*node+1, mid+1, en, ind, idx);}
    treee[idx][node]=treee[idx][2*node] + treee[idx][2*node+1];
    return;
}

int BS(int idx, int val){
    int l=0, r=factor[idx].size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(factor[idx][mid]==val){return mid;}
        else if(factor[idx][mid]<val){l=mid+1;}
        else{r=mid-1;}
    }
    return -1;
}



void solve(int T){
    //db(factor)
    int n,m;    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<factor[m].size(); i++){
        build(1, 1, n, i, factor[m][i]);
    }

    int q;  cin>>q;
    while(q--){
        int type;   cin>>type;
        if(type==1){
            int idx, val;   cin>>idx>>val;
            for(int i=0; i<factor[m].size(); i++){
                bool z1=0,z2=0;
                if(arr[idx]%factor[m][i]!=0){z1=1;}
                if(val%factor[m][i]!=0){z2=1;}
                if(z1!=z2){
                    update(1, 1, n, idx, i);
                }
            }
            arr[idx]=val;
        }
        else{
            int l,r,k;  cin>>l>>r>>k;
            k=gcd(m,k);
            int zzz=BS(m, k);
            int ans=query(1, 1, n, l, r, zzz);
            cout<<ans<<endl;
        }
    }

}



//DRINK WATER
int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////
    find_all_factor();
    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}