#include<bits/stdc++.h>                                         //DRINK WATER
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using u128 = __uint128_t;
#define int long long
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


template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;


#ifndef ONLINE_JUDGE
#define db(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define db(x)
#endif
void _print(int t){cerr<<t;}
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
template<class T>void _print(ordered_set<T>&os){cerr<<"[ ";for(auto it=os.begin();it!=os.end();++it){_print(*it);cerr<<"  ";}cerr<<"]";}
template<class T>void _print(ordered_multiset<T>&os){cerr<<"=[ ";for(auto it=os.begin();it!=os.end();++it){_print(*it);cerr<<"  ";}cerr<<"]";}
template<class T,size_t NN>void _print(T(&z)[NN]){cerr<<"[ ";for(size_t i=0;i<NN;i++){_print(z[i]);cerr<<"  ";}cerr<<"]";}

template<typename T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x : a) cin >> x; return cin; }




/// nCr = n! / r! * (n-r)!
/// nPr = n! / (n-r)!

// .order_of_key(x)
// *.find_by_order(x)

//substr
//cin.ignore();

//__builtin_popcount()
//memset(dp, -1, sizeof(dp));

//cout<<"Case "<<T<<": ";


#define YES {cout<<"Yes"<<endl;}
#define NO  {cout<<"No"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE



int n;
ll x; 
int n1,n2;

vector<ll>ans_1, ans_2;


void xxx(vector<ll>&a, ll sum , int pos){
    if(pos>=n1){ans_1.pb(sum);    return;}
    xxx(a, sum, pos+1);
    if((sum+a[pos])<=x){
        xxx(a, sum+a[pos], pos+1);
    }
    return;
}

void yyy(vector<ll>&b, ll sum , int pos){
    if(pos>=n2){ans_2.pb(sum);    return;}
    yyy(b, sum, pos+1);
    if((sum+b[pos])<=x){
        yyy(b, sum+b[pos], pos+1);
    }
    return;
}

int BS_r(int val){
    int ans=ans_1.size();
    int l=0, r=ans_1.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(val+ans_1[mid]>x){
            r=mid-1;
            ans=mid;
        }
        else{l=mid+1;}
    }
    return ans-1;
}


int BS_l(int val){
    int ans=-1;
    int l=0, r=ans_1.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(val+ans_1[mid]<x){
            l=mid+1;
            ans=mid;
        }
        else{r=mid-1;}
    }
    return ans+1;
}


void solve(int T){            ///   (DRINK WATER)
    cin>>n>>x;

    n1=(n+1)/2;
    n2=n-n1;

    vector<ll>a(n1),b(n2); 

    cin>>a; cin>>b;
    

    xxx(a, 0, 0);
    yyy(b, 0, 0);

    sort(all(ans_1));
    sort(all(ans_2));

    ll ans=0; 
    for(int i=0; i<ans_2.size(); i++){
        int LL=BS_l(ans_2[i]);
        int RR=BS_r(ans_2[i]);
        if(LL<=RR){ans+=(RR-LL+1);}
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