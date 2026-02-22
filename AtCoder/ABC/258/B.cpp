#include<bits/stdc++.h>                                         //DRINK WATER
#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;


//#define read()          freopen("folding.in","r",stdin)
//#define write()         freopen("folding.out","w",stdout)

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
const ll MOD   = 1e9+7;
const double PI = acos(-1);       //3.1415926535897932384626

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};



//#define int long long



char arr[12][12];

int n;

ll powMod(ll x, ll n){ll res=1; while(n){if(n&1){res=(res*x);} x=(x*x); n>>=1;} return res;}




//----------NO DRINK WATER----------(RAMADAN)
void solve(int T){
    cin>>n;
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    ll ans=0;
    for(int i=1; i<=n ;i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<8; k++){
                ll temp1=0;
                ll temp2=0;
                int x=i,y=j;
                for(int zz=1; zz<=n; zz++){
                    temp1*=10;
                    temp1+=(arr[x][y]-'0');
                    temp2+=(arr[x][y]-'0')*powMod(10,n-zz);
                    x+=dx[k];
                    y+=dy[k];
                    if(x<1){x=n;}
                    if(y<1){y=n;}
                    if(x>n){x=1;}
                    if(y>n){y=1;}   
                }
                ans=max(ans,temp1);
                ans=max(ans,temp2);
            }
        }
    }
    cout<<ans<<endl;
}





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

