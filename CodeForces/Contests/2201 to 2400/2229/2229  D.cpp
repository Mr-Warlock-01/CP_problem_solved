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
const int N=1e5+7;
int n;
int left_parent[N];
int right_parent[N];

int find_left(int x){
    if(x==left_parent[x]){return x;}
    return left_parent[x]= find_left(left_parent[x]);
}

int find_right(int x){
    if(x==right_parent[x]){return x;}
    return right_parent[x]= find_right(right_parent[x]);
}


int A[N],B[N];
pair<pair<int,int>,int>treee[4*N];


void build(int node, int st, int en){
    if(st==en){  treee[node] = {{min(A[st],B[st]),max(A[st],B[st])},st}; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=min(treee[2*node],treee[2*node+1]);
    return;
}

pair<pair<int,int>,int> query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return {{LLMax,LLMax},LLMax};}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    pair<pair<int,int>,int> q1= query(2*node, st, mid, l, r);
    pair<pair<int,int>,int> q2= query(2*node+1, mid+ 1, en, l, r);
    return min(q1,q2);
}

void update(int node, int st, int en, int ind, pair<int,int> val){
    if(st==en){ treee[node].ff=val;   return;}
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){update(2*node,st, mid, ind, val);}
    else{update(2*node+1, mid+1, en, ind, val);}
    treee[node]=min(treee[2*node],treee[2*node+1]);
    return;
}

void erase(int x){
    left_parent[x]=x-1;
    right_parent[x]=x+1;
    update(1, 1, n, x, {LLMax, LLMax});
}


void merge(int idx_1, int idx_2){
    vector<int>v;
    v.pb(A[idx_1]);
    v.pb(A[idx_2]);
    v.pb(B[idx_1]);
    v.pb(B[idx_2]);
    sort(all(v));
    A[idx_1]=v[1];
    B[idx_1]=v[2];
    erase(idx_2);
    update(1, 1, n, idx_1, {v[1], v[2]});
}

void solve(int T){
      cin>>n;
    for(int i=1; i<=n; i++){cin>>A[i];}
    for(int i=1; i<=n; i++){cin>>B[i];}
    for(int i=0; i<n+2; i++){
        left_parent[i]=right_parent[i]=i;
    }

    build(1, 1, n);

    for(int i=1; i<n; i++){
        auto z=query(1, 1, n, 1, n);
        int IDX=z.ss;
        int left_idx=find_left(IDX-1);
        int right_idx=find_right(IDX+1);
        if(left_idx<1){
            // do IDX, right_idx
            merge(IDX, right_idx);
        }
        else if(right_idx>n){
            //do IDX, left_idx
            merge(IDX, left_idx);
        }
        else{
            pair<int,int> LEFT={min(A[left_idx],B[left_idx]), max(A[left_idx],B[left_idx])};
            pair<int,int> RIGHT={min(A[right_idx],B[right_idx]), max(A[right_idx],B[right_idx])};
            if(LEFT<RIGHT){
                //do IDX, left_idx
                merge(IDX, left_idx);
            }
            else{
                // do IDX, right_idx
                merge(IDX, right_idx);
            }
        }
    }
    
    cout<<query(1, 1, n, 1, n).ff.ff<<endl;    

    
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