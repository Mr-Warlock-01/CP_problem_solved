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


const int N=17;
string s[N];
int arr[N][N];
int dp[N][1<<N];
int n;

bool cmp(string &a, string &b){             //cheeck if a<b
    int z=min(a.size(),b.size());
    for(int i=0; i<z; i++){
        if(a[i]<b[i]){return 0;}
        if(a[i]>b[i]){return 1;}
    }
    if(a.size()<b.size()){return 0;}
    return 1;
}

int zzz(int a, int b){                      //last xth chreacter of b if a in placed before it
    int z=0;
    while(z+s[b].size()<=s[a].size()){
        bool flag=1;
        for(int i=z, j=0; j<s[b].size(); i++,j++){
            if(s[a][i]!=s[b][j]){flag=0; break;}
        }
        if(flag){return -1;}
        z++;
    }

    for(int z=min(s[a].size(),s[b].size())-2; z>=0; z--){
        bool flag=1;
        for(int i=s[a].size()-1, j=z; j>=0; j--, i--){
            if(s[a][i]!=s[b][j]){flag=0; break;}
        }
        if(flag){return s[b].size()-z-1;}
    }
    return s[b].size();             
}


int xxx(int last, int mask){                //dp count
    if(__builtin_popcount(mask)==n){return 0;}
    if(dp[last][mask]!=-1){return dp[last][mask];}

    int ans=1e8;
    for(int i=0; i<n; i++){
        if(((mask>>i)&1)==0){
            ans=min(ans,xxx(i, mask|(1<<i))+arr[last][i]);
        }
    }
    return dp[last][mask]=ans;
}


void print(int last, int mask){             //dp print
    if(__builtin_popcount(mask)==n){return;}
    string sss="";
    int indx=-1, len=1e8, x;
    for(int i=0; i<n; i++){
        if(((mask>>i)&1)==0){
            x=xxx(i, mask|(1<<i))+arr[last][i];
            if(indx==-1){
                len=x;
                indx=i;
                sss=s[i].substr(s[i].size()-arr[last][i],arr[last][i]);
            }
            else{
                if(x<len){
                    len=x;
                    indx=i;
                    sss=s[i].substr(s[i].size()-arr[last][i],arr[last][i]);
                }
                if(x==len){
                    string haha=s[i].substr(s[i].size()-arr[last][i],arr[last][i]);
                    if(cmp(sss,haha)){
                        len=x;
                        indx=i;
                        sss=s[i].substr(s[i].size()-arr[last][i],arr[last][i]);
                    }
                }
            }
        }
    }
    cout<<sss;
    print(indx, mask|(1<<indx));    
}



void solve(int T){         ///   (DRINK WATER)
    cin>>n;
    for(int i=0; i<n; i++){cin>>s[i];}

    memset(arr,0,sizeof arr);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){continue;}
            arr[i][j]=zzz(i,j);
        }
    }
    for(int i=0; i<n; i++){arr[n][i]=s[i].size();}
    
    memset(dp,-1,sizeof dp);
    int mask=0;
    for(int i=0; i<n; i++){
        if(((mask>>i)&1)==1){continue;}
        for(int j=0; j<n; j++){
            if(i==j){continue;}
            if(arr[i][j]==-1){mask=mask|(1<<j);}
        }
    }
    
    cout<<"Case "<<T<<": ";
    print(n,mask);
    cout<<endl;
return;
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