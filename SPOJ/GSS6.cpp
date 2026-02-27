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
//const int N=1e5+7;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    int prior,size;
    int val;
    int sum,ans,left_best,right_best;
    node *l,*r;
    node(int value){
        l=r=nullptr;
        val=value;
        sum=value;
        ans=value;
        left_best=value;
        right_best=value;
        size=1;
        prior=rnd();
    }
};

typedef node* pnode;

int sz(pnode t){
    return t?t->size:0;
}

void upd_sz(pnode t){
    if(t)t->size=sz(t->l)+1+sz(t->r);
}

void fix_node_info(pnode& t,pnode l,pnode r){
    if(!l || !r)return;// void(t = l?l:r);
    t->ans = max({l->ans, r->ans, l->right_best + r->left_best});
    t->left_best= max(l->left_best, l->sum+ r->left_best);
    t->right_best= max(r->right_best, r->sum+ l->right_best);  
    t->sum = l->sum +r->sum;
}

void update_node_info(pnode t){
    if(!t){return;}
    //reset node
    t->sum = t->ans = t->left_best = t->right_best = t->val;
    fix_node_info(t, t->l, t);
    fix_node_info(t, t, t->r);
}


void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t)return void(l=r=nullptr);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos){
        split(t->r,t->r,r,pos,curr_pos+1); l=t;
    }
    else{
        split(t->l,l,t->l,pos,add); r=t;
    }
    upd_sz(t);
    update_node_info(t);
}

void merge(pnode &t,pnode l,pnode r){
    if(!l || !r){t = l?l:r;}
    else if(l->prior>r->prior){
        merge(l->r,l->r,r); t=l;
    }
    else{
        merge(r->l,l,r->l);t=r;
    }
    upd_sz(t);
    update_node_info(t);
}



void solve(int T){
    int n;  cin>>n;
    
    pnode root=nullptr;

    for(int i=0; i<n; i++){
        int a;  cin>>a;
        merge(root,root, new node(a));
    }   

    int q;  cin>>q;
    while(q--){
        char type;   cin>>type;
        if(type=='I'){
            int idx,val;    cin>>idx>>val;
            idx--;
            pnode l,r;
            split(root, l, r, idx-1);
            merge(root, l, new node(val));
            merge(root, root, r);
        }
        else if(type=='D'){
            int idx;   cin>>idx;
            idx--;
            pnode l,r;
            split(root, root, r, idx-1);
            split(r, l, r, 0);
            merge(root,root,r);
        }
        else if(type=='R'){
            int idx,val;    cin>>idx>>val;
            idx--;
            pnode l,r;
            split(root, root, r, idx-1);
            split(r, l, r, 0);
            merge(root, root, new node(val));
            merge(root, root, r);        }
        else{
            int L_idx, R_idx;   cin>>L_idx>>R_idx;
            L_idx--; R_idx--;
            pnode l,ans_part,r;
            split(root, l, r, R_idx);
            split(l,l, ans_part, L_idx-1);
            int result=ans_part->ans;
            merge(root,l,ans_part);
            merge(root,root,r);
            cout<<result<<endl;
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