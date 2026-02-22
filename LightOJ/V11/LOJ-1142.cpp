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

//#define int ll

const int N=30;
const int M=10;

using Matrix = array<array<int, N>, N>;

Matrix Seq;

Matrix matrix_add(Matrix &A, Matrix &B, int M_sz){
    Matrix ans={};
    for(int i=0; i<M_sz; i++){
        for(int j=0; j<M_sz; j++){
            ans[i][j]=(A[i][j]+B[i][j])%M;
        }
    }
    return ans;
}

Matrix matrix_mul(Matrix &A, Matrix &B, int M_sz) {
    Matrix res = {};
    for(int i=0; i<M_sz; i++){
        for(int j=0; j<M_sz; j++){
            for(int k=0; k< M_sz; k++){
                res[i][j] = (res[i][j] + ((A[i][k] * B[k][j]) % M)) % M;
            }
        }
    }
    return res;
}

Matrix matrix_pow(Matrix mat, int n, int M_sz) {
    Matrix res = {};
    for(int i=0; i<M_sz; i++){res[i][i]=1;}
    while(n){
        if(n&1){res = matrix_mul(res, mat, M_sz);}
        if(n>0){mat = matrix_mul(mat, mat, M_sz);}
        n>>=1;
    }
    return res;
}

Matrix matrix_bonomial(int n, int M_sz){
    if(n==1){return Seq;}
    Matrix sum=matrix_bonomial(n/2, M_sz);
    Matrix res=matrix_pow(Seq, n/2, M_sz);
    Matrix ans=matrix_mul(res, sum, M_sz);
    ans=matrix_add(ans, sum, M_sz);
    if(n&1){
        res=matrix_pow(Seq, n, M_sz);
        ans=matrix_add(ans, res, M_sz);
    }
    return ans;
} 
 
void solve(int T){            ///   (DRINK WATER)
    int n,k;    cin>>n>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>Seq[i][j];
        }
    }

    Matrix ans=matrix_bonomial(k, n);

    cout<<"Case "<<T<<": "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}
 


 

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