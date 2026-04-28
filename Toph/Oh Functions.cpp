// https://toph.co/p/oh-functions

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
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


#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll invMod(ll x, ll M){return powMod(x, M-2, M);}


#define int ll

const int N=2;
const int M=1000000007;
int inv3=333333336;


using Matrix = array<array<ll, N>, N>;
Matrix matrix_mul(Matrix &A, Matrix &B, int M_sz) {
    Matrix res = {};
    for(int i=0; i<M_sz; i++) {
        for(int j=0; j<M_sz; j++) {
            for(int k=0; k< M_sz; k++) {
                res[i][j] = (res[i][j] + ((A[i][k] * B[k][j]) % M)) % M;
            }
        }
    }
    return res;
}

Matrix matrix_pow(Matrix &mat, int n, int M_sz) {
    Matrix res = {};
    for(int i=0; i<M_sz; i++){res[i][i]=1;}
    while(n){
        if(n&1){res = matrix_mul(res, mat, M_sz);}
        if(n>0){mat = matrix_mul(mat, mat, M_sz);}
        n>>=1;
    }
    return res;
}


Matrix Seq, Pat, res;

void solve(int T){      //DRINK WATER
    int n;  cin>>n;
    int b= powMod(2, n+1, M-1);
    b=(b-1+M-1)%(M-1);
    int f_g= powMod(3, b ,M);
    //f_g=(f_g*inv3)%M;

    Seq={12, M-21,
        0,  1};
    Pat={0,0,
        1,0};

    Seq = matrix_pow(Seq, n, 2);
    res = matrix_mul(Seq, Pat, 2);
    int f_2g=res[0][0];
    int g= (f_g - f_2g+M)%M;
    g=(g*inv3)%M ;
    int f=(f_g-g+M)%M;

    cout<<"Case "<<T<<": ";
    cout<<f<<" "<<g<<endl;       
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