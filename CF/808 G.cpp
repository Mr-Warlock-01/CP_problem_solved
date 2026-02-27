#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
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
const ll MOD   = 1e9+7;
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


//#define int ll

const int N=1e5+7;

string txt,patt;
int n,m;
int aut[N][26];
vector<vector<int>>dp;

vector<int>build_lps(string pat){
    int sz=pat.size(); 
    vector<int>lps(sz); 
    for(int i=1; i<sz; i++){
        int k=lps[i - 1];
        while((k>0) && (pat[i] != pat[k])){k=lps[k-1];}
        if(pat[i]==pat[k]){k++;}
        lps[i]=k;
    }
    return lps;
}

void KMP_automation(string s){
    s += '#';
    int sz=s.size();
    vector<int>pi=build_lps(s);
    for(int i=0; i<sz; i++) {
        for(int c=0; c<26; c++) {
            if(i>0 && ('a'+c)!=s[i]){
                aut[i][c]=aut[pi[i-1]][c];
            }
            else{
                aut[i][c]= i +(('a'+c)==s[i]);
            }
        }
    }
}

//kmp automation indicates -> k prefix match er por 'x' char bosaile new k koto;


int xxx(int i, int j){
    if(i>=n){return (j==m);}
    if(dp[i][j]!=-1){return dp[i][j];}

    int ans=0;
    if(txt[i]=='?'){
        for(int k=0; k<26; k++){
            ans=max(ans, xxx(i+1, aut[j][k]));
        }
    }
    else{
        ans=xxx(i+1, aut[j][txt[i]-'a']);
    }
    if(j==m){ans++;}
    return dp[i][j]= ans;
}


void solve(int T){
    cin>>txt>>patt;
    n=txt.size(); m=patt.size();
    if(m>n){cout<<0<<endl; return;}
    dp.resize(n, vector<int>(m+1,-1));
    KMP_automation(patt);
    int ans=xxx(0,0);
    cout<<ans<<endl;
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