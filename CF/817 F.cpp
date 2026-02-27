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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    int prior,size;
    int val,sum;
    node *l,*r;
    node(int value){
        l=r=nullptr;
        val=value;
        sum=value;
        size=1;
        prior=rnd();
    }
};

typedef node* pnode;

int sz(pnode t){
    if (t == nullptr){return 0;}
    return t->size;
}

void upd_sz(pnode t){
    if(t!=nullptr){
        t->size=sz(t->l)+1+sz(t->r);
    }
}

void split(pnode t,pnode &l,pnode &r,int key){
    if(!t){l=r=nullptr;}
    else if(t->val<=key){
        split(t->r,t->r,r,key);
        l=t;
    }
    else{
        split(t->l,l,t->l,key);
        r=t;
    }
    upd_sz(t);
}

void merge_treap(pnode &t, pnode l,pnode r) {
    if(!l || !r){
        t=l?l:r;
        return;
    } 
    if(l->prior < r->prior){swap(l, r);}
    node *L, *R;
    split(r, L, R, l->val);
    merge_treap(l->r,l->r, R);
    merge_treap(l->l,L, l->l);
    t=l;
    upd_sz(t);
}

int find_1st(pnode t){
    if(t->l==nullptr){
        return t->val;
    }
    return find_1st(t->l);  
}
void output(pnode t){
    if(t==nullptr){return;}
    output(t->l);
    cout<<t->val<<" ";
    output(t->r);
}


map<int,int>mp, rev_mp;

void solve(int T){
    int q;  cin>>q;
    vector<pair<int,pair<int,int>>>query(q);
    vector<int>v;

    for(int i=0; i<q; i++){
        cin>>query[i].ff>>query[i].ss.ff>>query[i].ss.ss;
        v.pb(query[i].ss.ff);
        if(query[i].ss.ff>1){
            v.pb(query[i].ss.ff-1);
        }
        v.pb(query[i].ss.ff+1);
        v.pb(query[i].ss.ss);
        if(query[i].ss.ss>1){
            v.pb(query[i].ss.ss-1);
        }
        v.pb(query[i].ss.ss+1);
    }    

    sort(all(v));
    int sz=uniq(v);

    

    int x=1;
    pnode _missing=nullptr;

    if(v[0]!=1){
        x++;
        mp[1]=1;
        rev_mp[1]=1;
        merge_treap(_missing,_missing, new node(1));
    }

    for(int i=0; i<sz; i++){
        mp[v[i]]=x;
        rev_mp[x]=v[i];
        merge_treap(_missing,_missing, new node(x));
        x++;
    }

    pnode root=nullptr;


   for(int i=0; i<q; i++){
        int type=query[i].ff;
        int l=query[i].ss.ff;
        int r=query[i].ss.ss;
        l=mp[l];
        r=mp[r];
        if(type==1){
            pnode a1=nullptr;
            pnode a2=nullptr;
            split(_missing, _missing, a1, l-1);
            split(a1, a1, a2, r);
            merge_treap(_missing, _missing, a2);
            merge_treap(root, root, a1);
        }
        else if(type==2){
            pnode a1=nullptr;
            pnode a2=nullptr;
            split(root, root, a1, l-1);
            split(a1, a1, a2, r);
            merge_treap(root, root, a2);
            merge_treap(_missing, _missing, a1);
        }
        else{
            pnode a1=nullptr;
            pnode a2=nullptr;
            split(_missing, _missing, a1, l-1);
            split(a1, a1, a2, r);
            merge_treap(_missing, _missing, a2);

            pnode a3=nullptr;
            pnode a4=nullptr;
            split(root, root, a3, l-1);
            split(a3, a3, a4, r);
            merge_treap(root, root, a4);

            merge_treap(root, root, a1);
            merge_treap(_missing, _missing, a3);
        }

        int ans=find_1st(_missing);
        ans=rev_mp[ans];
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