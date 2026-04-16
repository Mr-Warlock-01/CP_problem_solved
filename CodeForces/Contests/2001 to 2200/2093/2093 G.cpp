#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
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

//#define int ll
const int NN=2e5+5;
int n,k;  
int arr[NN];


struct TrieNode {
    int  cnt;
    TrieNode *nxt[2];
    TrieNode() {
        cnt=-1;
        nxt[0] = NULL;
        nxt[1] = NULL;
    }
}*root;

void insert(int x, int pos){
    TrieNode *cur = root;
    for (int i=30; i>=0; i--) {
        int idx=(x>>i)&1;
        if((cur -> nxt[idx])== NULL){cur -> nxt[idx] = new TrieNode();}
        cur = cur -> nxt[idx];
        cur->cnt=pos;
    }
return;
}

int query(int x){
    TrieNode *cur = root;
    int ans=-1;
    int num=0;
    for(int i=30; i>=0; i--){
        int idx=(x>>i)&1;
        int f=0;
        if(cur->nxt[idx^1]!=NULL && (num|(1<<i))>=k){
            ans=max(ans, cur->nxt[idx^1]->cnt); f=1;
        }
        if(cur->nxt[idx^1]!=NULL && f==0){
            cur=cur->nxt[idx^1];
            num|=(1<<i);    f=2;
        }
        if(cur->nxt[idx]!=NULL &&  f==1 || f==0){
            cur=cur->nxt[idx]; f=2;
        }
        if(f==0 || f==1){break;}

    }
    return ans;
}


void del(TrieNode *cur) {
    if(cur->nxt[0]!=NULL){del(cur->nxt[0]);}
    if(cur->nxt[1]!=NULL){del(cur->nxt[1]);}
    delete(cur);
return;
}


void solve(int T){   
    cin>>n>>k;
    for(int i=0; i<n; i++){cin>>arr[i];}
    if(k==0){cout<<"1"<<endl; return;}
    
    root = new TrieNode();  
    int ans=INT_MAX;
    insert(arr[0],0);
    for(int i=1; i<n; i++){
        int temp=query(arr[i]);
        if(temp!=-1){
            ans=min(ans, i-temp+1);
        }
        insert(arr[i], i);
    }
    del(root);
    if(ans==INT_MAX){ans=-1;}
    cout<<ans<<endl;
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