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
// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #else
// #define db(x)
// #endif


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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    int prior,size;
    int val,sum;
    bool reverse;
    node *l,*r;
    node(int value){
        l=r=nullptr;
        val=value;
        sum=value;
        size=1;
        reverse=0;
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


void reverse_check(pnode t){
    if(t==nullptr){return;}
    if(t->reverse==1){
        swap(t->l, t->r);
        if(t->l!=nullptr){t->l->reverse^=1;}
        if(t->r!=nullptr){t->r->reverse^=1;}
        t->reverse=0;
    }
}

void fix_node_info(pnode& t,pnode l,pnode r){
    if(!l || !r)return;// void(t = l?l:r);
    t->sum = l->sum +r->sum;
}

void update_node_info(pnode t){
    if(!t){return;}
    reverse_check(t);
    t->sum = t->val;     //reset node
    fix_node_info(t, t->l, t);
    fix_node_info(t, t, t->r);
}




void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t){l=r=nullptr; return;}
    reverse_check(t);
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
    reverse_check(t);
    reverse_check(l);
    reverse_check(r);
    if(!l || !r){t = l?l:r;}
    else if(l->prior>r->prior){
        merge(l->r,l->r,r); 
        t=l;
    }
    else{
        merge(r->l,l,r->l);
        t=r;
    }
    upd_sz(t);
    update_node_info(t);
}

void output(pnode t){
    if(t==nullptr){return;}
    reverse_check(t);
    output(t->l);
    cout<<t->val;
    output(t->r);
}


void solve(int T){
    int n,q;    cin>>n>>q;
    pnode root=nullptr;

    for(int i=0; i<n; i++){
        int a;  cin>>a;
        merge(root,root, new node(a));  
    }
    while(q--){
        int ty; cin>>ty;
        int l,r;    cin>>l>>r;
        l--;    r--;
        pnode RIGHT,MID;
        split(root, root, RIGHT, r);
        split(root, root, MID, l-1);
        if(ty==1){
            MID->reverse^=1;
        }
        else{
            cout<<MID->sum<<endl;
        }
        merge(root,root,MID);
        merge(root,root,RIGHT);
    }
}



    

int32_t main(){             //DRINK WATER
    //war();
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

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/  