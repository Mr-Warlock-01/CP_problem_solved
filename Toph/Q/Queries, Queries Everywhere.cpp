// https://toph.co/p/queries-queries-everywhere

#include<bits/stdc++.h>                                         //DRINK WATER
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using u128 = __uint128_t;


#define read()  freopen("folding.in","r",stdin)
#define write() freopen("folding.out","w",stdout)

#define endl "\n"
#define int long long
#define double long double
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define uniq(x) (unique(x.begin(), x.end()) - x.begin())
#define deci(x) cout << fixed << setprecision(x);
#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);


#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}

///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

const int N=200010;

int arr[N];
int sum_tree[4*N];
int min_tree[4*N];
int LLmax=1e17;

///segment tree     //segment tree      //segment tree      //segment tree      //segment tree      //segment tree
void sum_build(int node, int st, int en){
    if(st==en){  sum_tree[node] = arr[st]; return;}
    int mid=((en-st)/2)+st;
    sum_build(2*node, st, mid);
    sum_build(2*node+1, mid+1, en);
    sum_tree[node]=sum_tree[2*node]+sum_tree[2*node+1];
    return;
}

int sum_query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return sum_tree[node];}
    int mid=((en-st)/2)+st;
    int q1= sum_query(2*node, st, mid, l, r);
    int q2= sum_query(2*node+1, mid+ 1, en, l, r);
    return q1+q2;
}

void sum_update(int node, int st, int en, int ind, int val){
    if(st==en){sum_tree[node]=val;   return;}
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){    sum_update(2*node,st, mid, ind, val);}
    else{                       sum_update(2*node+1, mid+1, en, ind, val);}
    sum_tree[node]=sum_tree[2*node] + sum_tree[2*node+1];
    return;
}


void min_build(int node, int st, int en){
    if(st==en){  min_tree[node] = arr[st]; return;}
    int mid=((en-st)/2)+st;
    min_build(2*node, st, mid);
    min_build(2*node+1, mid+1, en);
    min_tree[node]=min(min_tree[2*node],min_tree[2*node+1]);
    return;
}

int min_query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return LLmax;}
    else if(st>=l && en<=r){return min_tree[node];}
    int mid=((en-st)/2)+st;
    int q1= min_query(2*node, st, mid, l, r);
    int q2= min_query(2*node+1, mid+ 1, en, l, r);
    return min(q1,q2);
}

void min_update(int node, int st, int en, int ind, int val){
    if(st==en){min_tree[node]=val;   return;}
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){    min_update(2*node,st, mid, ind, val);}
    else{                       min_update(2*node+1, mid+1, en, ind, val);}
    min_tree[node]=min(min_tree[2*node],min_tree[2*node+1]);
    return;
}

void SOLVE(int T){         ///MAIN  (DRINK WATER)
    int n,q;      cin>>n>>q;
    for(int i=0; i<n; i++){cin>>arr[i];}

    min_build(1, 0, n-1);
    sum_build(1, 0, n-1);

    while(q--){
        int x;  cin>>x;
        if(x==1){
            int indx,val;   cin>>indx>>val;
            sum_update(1, 0, n-1, indx-1, val);
            min_update(1, 0, n-1, indx-1, val);
        }
        else{
            int L,R;    cin>>L>>R;
            int ans=sum_query(1, 0, n-1, L-1, R-1);
            ans-=min_query(1, 0, n-1, L-1, R-1);
            cout<<ans<<endl;
        }
    }
}




signed main(){
    war();
    //read();   write();
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        SOLVE(T);
    }
return 0;
}
