#include<bits/stdc++.h>                                         //DRINK WATER
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


//template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//template<typename T>using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;


#ifndef ONLINE_JUDGE
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
#endif
void _print(int t){cerr<<t;}
void _print(long long t){cerr<<t;}
void _print(string t){cerr<<t;}
void _print(char t){cerr<<t;}
void _print(double t){cerr<<t;}
void _print(bool t){cerr<<t;}
template<class T,class V>void _print(pair<T,V>p){cerr<<"{";_print(p.ff);cerr<<","; _print(p.ss);cerr<<"}";}
template<class T>void _print(vector <T> v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T>v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T>v){cerr<<"[ ";for(T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T,V>v){cerr<<"[ ";for(auto i:v){_print(i);cerr<<" ";}cerr<< "]";}
template<class T>void _print(stack<T>st){cerr<<"[ ";stack<T>temp;while(!st.empty()){temp.push(st.top());st.pop();}while(!temp.empty()){_print(temp.top());cerr<<" ";temp.pop();}cerr<<"]";}
template<class T>void _print(queue<T>q){cerr<<"[ ";while(!q.empty()){_print(q.front());cerr<<" ";q.pop();}cerr << "]";}
template<class T>void _print(priority_queue<T>pq){cerr<<"[ ";priority_queue<T>temp=pq;while(!temp.empty()){_print(temp.top());temp.pop();if(!temp.empty())cerr<<" ";}cerr<<"]";}
template<class T>void _print(priority_queue<T,vector<T>,greater<T>>pq){cerr<<"[ ";priority_queue<T,vector<T>,greater<T>>temp=pq;while(!temp.empty()){_print(temp.top());temp.pop();if(!temp.empty())cerr<<" ";}cerr<<"]";}
//template<class T>void _print(ordered_set<T>&os){cerr<<"[ ";for(auto it=os.begin();it!=os.end();++it){_print(*it);cerr<<"  ";}cerr<<"]";}
//template<class T>void _print(ordered_multiset<T>&os){cerr<<"=[ ";for(auto it=os.begin();it!=os.end();++it){_print(*it);cerr<<"  ";}cerr<<"]";}
template<class T,size_t NN>void _print(T(&z)[NN]){cerr<<"[ ";for(size_t i=0;i<NN;i++){_print(z[i]);cerr<<"  ";}cerr<<"]";}

template<typename T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x : a) cin >> x; return cin; }




/// nCr = n! / r! * (n-r)!
/// nPr = n! / (n-r)!

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
ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll invMod(ll x, ll M){return powMod(x, M-2, M);}


const int b1= 137;
const int b2= 277;
const int m1= 14457881;
const int m2= 11457857;

const int N=1e6+3;
int lps[N];
int hash_1[N], hash_2[N];
pair<int,int> invPPP[N];

void build_lps(string &pat) {
    int sz=pat.size(); 
    for(int i=1; i<sz; i++){
        int k=lps[i - 1];
        while((k>0) && (pat[i] != pat[k])){k=lps[k-1];}
        if(pat[i]==pat[k]){k++;}
        lps[i]=k;
    }
return;
}

pair<int,int>find_hash(int l, int r){
    if(l==0){return {hash_1[r],hash_2[r]};}

    int hhh1= (hash_1[r]-hash_1[l-1]+m1)%m1;     hhh1=(1ll*hhh1* invPPP[l].ff)%m1;
    int hhh2= (hash_2[r]-hash_2[l-1]+m2)%m2;     hhh2=(1ll*hhh2* invPPP[l].ss)%m2;
    return {hhh1, hhh2};
}


void solve(int T){
    string s;   cin>>s;
    int n=s.size();
    build_lps(s);
    
    int h_1=0, h_2=0;
    int p1=1, p2=1;
    for(int i=0; i<n; i++){
        hash_1[i]= (h_1+(1ll*s[i]*p1)%m1)%m1;
        hash_2[i]= (h_2+(1ll*s[i]*p2)%m2)%m2;
        h_1=hash_1[i];
        h_2=hash_2[i];
        p1=(1ll*p1*b1)%m1;
        p2=(1ll*p2*b2)%m2;
    }

    p1=invMod(powMod(b1, n-1, m1),m1);
    p2=invMod(powMod(b2, n-1, m2),m2);

    for(int i=n-1; i>=0; i--){
        invPPP[i]={p1,p2};
        p1=(1ll*p1*b1)%m1;
        p2=(1ll*p2*b2)%m2;
    }

    int ans_len=0;

    for(int i=1; i<(n-1); i++){
        if(lps[i]==0){continue;}
        auto mid_h= find_hash(i-lps[i]+1, i);
        auto last_h=find_hash( n-lps[i], n-1);
        if(mid_h==last_h){ans_len=max(ans_len, lps[i]);}
    }


    if(ans_len==0){cout<<"Just a legend";}
    else{
        for(int i=0; i<ans_len; i++){cout<<s[i];}
    }

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