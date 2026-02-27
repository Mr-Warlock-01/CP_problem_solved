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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;  x=(x^(x>>30))*0xbf58476d1ce4e5b9;   x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t>x) const { 
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); 
        return splitmix64(x.first+FIXED_RANDOM)^(splitmix64(x.second+FIXED_RANDOM)>>1); 
    } 
    size_t operator()(const string& str) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t hash = FIXED_RANDOM;
        for(char c:str) {hash^=c+0x9e3779b9+(hash<<6)+(hash>>2);}
        return splitmix64(hash);
    }
};

const int N=1e5+3;
int arr[N];
vector<int>v[N];
set<int>ss;
gp_hash_table<int, int,custom_hash>mp;
int z=1;

void factorize_k(int k){
    for(int i=1; (i*i)<=k; i++){
        if(k%i==0){ss.insert(i);}
        if(k%i==0){ss.insert(k/i);}
    }
}

void new_k(int k){
    stack<int>st;
    for(auto u:ss){
        if(k%u!=0){st.push(u);}
    }

    while(!st.empty()){
        int z=st.top();
        st.pop();
        ss.erase(z);
    }
}

int khujtesi_re_vai(int pos){
    int main_ans=1e6;
    for(auto u:ss){
        int ans=1e6;
        int z=mp[u];
        int l=0, r=v[z].size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(v[z][mid]==pos){return pos;}
            else if(v[z][mid]>pos){ans=v[z][mid]; r=mid-1;}
            else{l=mid+1;}
        }
        main_ans=min(main_ans, ans);
    }
    return main_ans;
}

void clear_kori(){
    mp.clear();
    for(int i=1; i<z; i++){
        v[i].clear();
    }
    ss.clear();
    z=1;
}


void solve(int T){
    int n,q;  cin>>n>>q;
    for(int i=0; i<n; i++){cin>>arr[i];}

    clear_kori();

    for(int i=0; i<n; i++){
        if(mp[arr[i]]==0){mp[arr[i]]=z; z++;}
        v[mp[arr[i]]].pb(i);
    }

    while(q--){
        int k,l,r;  cin>>k>>l>>r;
        l--; r--;
        factorize_k(k);

        int ans=0;
        while(l<=r){
            int z=khujtesi_re_vai(l);
            if(z>r){ans+=(r-l+1)*k; break;}
            else{ans+=(z-l)*k; l=z;}
            while(k%arr[z]==0){k/=arr[z];}
            new_k(k);
        }
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
    cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}