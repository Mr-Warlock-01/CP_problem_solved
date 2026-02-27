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
#define int ll



const int N=2e5+7;
const int block_sz=2710; 
const int sq_root_de=320;

int arr[N];
int cnt[N];
int freq[N];
int ans[N];
map<int,int>mp;
ll L=1,R=0;

struct query{
    int l,r,t,idx;
    query(){}
    query(int l, int r, int t, int idx):l(l),r(r),t(t),idx(idx){}
    bool operator<(const query &q)const{
        int curl=l/block_sz, otherl = q.l/block_sz;
        int curr=r/block_sz, otherr = q.r/block_sz;
        if(curl^otherl){return curl<otherl;}
        if(curr^otherr){return curr<otherr;}
        return t<q.t;
    }
}queries[N];

struct update{
    int ind;
    int prev,nxt; 
    update(){}
    update(int ind,int prev,int nxt):ind(ind),prev(prev),nxt(nxt){}
}updates[N];


void add(int idx){
    int val=arr[idx];
    freq[cnt[val]]--;
    cnt[val]++;
    freq[cnt[val]]++;
}

void remove(int idx){
    int val=arr[idx];
    freq[cnt[val]]--;
    cnt[val]--;
    freq[cnt[val]]++;
}

void adjust(ll idx, int val){
    if((L<=idx) && (idx<=R)){
        remove(idx);
        arr[idx]=val;
        add(idx);
    }
    else{
        arr[idx]=val;
    }
}


void solve(int T){
    int n,q;    cin>>n>>q;
    int z=1;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        if(mp.find(arr[i])==mp.end()){mp[arr[i]]=z; z++;}
        arr[i]=mp[arr[i]];
    }

    int updateCnt=0;
    int queryCnt=0;

    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==2){ //update
            int idx,val;    cin>>idx>>val;
            if(mp.find(val)==mp.end()){mp[val]=z; z++;}
            val=mp[val];
            updates[updateCnt++]=update(idx,arr[idx],val);
            arr[idx]=val;
        }
        else{       //query
            int l,r; cin>>l>>r;
            queries[queryCnt]=query(l,r,updateCnt,queryCnt);
            queryCnt++;
        }
    }


    sort(queries,queries+queryCnt);
    for(int i=0;i<queryCnt;i++){
        while(L>queries[i].l){add(--L);}
        while(R<queries[i].r){add(++R);}
        while(L<queries[i].l){remove(L++);}
        while(R>queries[i].r){remove(R--);}

        while(updateCnt<queries[i].t){
            adjust(updates[updateCnt].ind,updates[updateCnt].nxt);
            updateCnt++;
        }
        while(updateCnt>queries[i].t){
            updateCnt--;
            adjust(updates[updateCnt].ind,updates[updateCnt].prev);
        }
        int res=1;
        while(freq[res]>0){res++;}
        ans[queries[i].idx]=res;
    }
    for(int i=0;i<queryCnt;i++){
        cout<<ans[i]<<endl;
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