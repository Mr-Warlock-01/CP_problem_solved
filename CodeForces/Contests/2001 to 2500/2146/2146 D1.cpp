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

#define int ll

const int N = 2;
const int NNN=32;

struct TrieNode{
    int  cnt;
    TrieNode * nxt[N];
    TrieNode(){
        cnt=0;
        for(int i=0; i<N; i++){ nxt[i] = NULL;}
    }
} *root;

struct Trie{
    TrieNode *root;
    Trie(){root = new TrieNode();}

    void insert(int x){
        TrieNode *cur = root;
        for (int i=NNN; i>=0; i--){
            int idx=x & ((1ll)<<i);
            if(idx!=0){idx=1;}
            if((cur -> nxt[idx])== NULL){
                cur -> nxt[idx] = new TrieNode();
            }
            cur = cur -> nxt[idx];
            cur->cnt++;
        }
    return;
    }

    int query(int x){ 
        TrieNode *cur = root;
        int ans=0;
        for(int i=NNN; i>=0; i--){
            int idx=x & ((1ll)<<i);
            if(idx!=0){idx=1;}
            idx^=1;

            if(cur -> nxt[idx] != NULL){
                cur = cur -> nxt[idx];
                if(idx==1){
                    ans|=(1ll<<i);
                }
            }
            else{
                cur = cur -> nxt[idx^1];
                if(idx==0){
                    ans|=(1ll<<i);
                }
            }
        }
        return ans;
    }

    void rem(int x, int pos){
        rem(root, x, pos);
    }

    void rem(TrieNode *cur, int x, int pos){
        if(pos<0){return;}
        int idx=x & ((1ll)<<pos);
        if(idx!=0){idx=1;}

        if((cur->nxt[idx])!=NULL){
            rem(cur->nxt[idx], x, pos-1);
            cur->nxt[idx]->cnt--;
        }
        if(cur->nxt[idx]->cnt==0) {
            free(cur->nxt[idx]);
            cur->nxt[idx]=NULL;
        }
    return;
    }


    int search(){ 
        TrieNode *cur = root;
        int ans=0;
        for(int i=NNN; i>=0; i--){
            int cnt_0=1e9,cnt_1=1e9; 
            if(cur -> nxt[0] != NULL){
                cnt_0=cur -> nxt[0] ->cnt;
            }
            if(cur -> nxt[1] != NULL){
                cnt_1=cur -> nxt[1] ->cnt;
            }

            if(cnt_0<cnt_1){
                cur = cur -> nxt[0];
            }
            else{
                cur = cur -> nxt[1];
                ans|=(1ll<<i);
            }
        }
        return ans;
    }

    ~Trie() {
        del(root);
    }

    void del(TrieNode *cur) {
        for(int i=0; i<N; i++){
            if(cur->nxt[i]!=NULL){del(cur->nxt[i]);}
        }
        delete(cur);
    return;
    }

    
};

void solve(int T){
    int l, r;    cin>>l>>r;
    Trie t;

    for(int i=l; i<=r; i++){
        t.insert(i);
    }

    int ans=0;
    vector<int>v(r-l+1);

    for(int i=l; i<=r; i++){
        int k=t.search();
        int z=t.query(k);
        ans+=(k|z);
        v[k-l]=z;
        v[z-l]=k;
        t.rem(z, NNN);
        if(k!=z){
            ans+=(k|z);
            t.rem(k, NNN);
            i++;
        }
    }

    cout<<ans<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
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


/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \


*/  