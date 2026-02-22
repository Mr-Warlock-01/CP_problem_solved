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
// *.find_by_order(x)

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



#define int ll
const int N=2;
const int M=1e9+7;

int Seq[N][N]={{1,1},
               {1,0}};   
int I[N][N];
int res[N][N];
int temp[N][N];

ll gcd (ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}
ll lcm (ll a, ll b){return ((a/gcd(a,b))*b);}
ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll invMod(ll x, ll M){return powMod(x, M-2, M);}

void mul_I_P(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ll ans=0;
            for(int k=0; k<N; k++){
                ans= (ans + ((I[i][k] * temp[k][j])%M))%M;
            }
            res[i][j]=ans;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            I[i][j]=res[i][j];
        }
    }
}

void mul_P_P(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ll ans=0;
            for(int k=0; k<N; k++){
                ans= (ans + ((temp[i][k] * temp[k][j])%M))%M;
            }
            res[i][j]=ans;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j]=res[i][j];
        }
    }
}

void matrix_exp(int n){
    memset(I, 0, sizeof I);

    for(int i=0; i<N; i++){I[i][i]=1;}

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j]=Seq[i][j];
        }
    }

    while(n){
        if(n&1){mul_I_P();}
        mul_P_P();
        n>>=1;
    }
}




void solve(int T){
    int n,x,m,y,k;  cin>>n>>x>>m>>y>>k;
    if(n>m){//n==small , m== big
        swap(n,m);
        swap(x,y);
    }  
    int f1,f2;
    bool flag=1;
    if(n>1){
        matrix_exp(n-2);    //a1f2 + b1f1= x;
        int a1=I[0][0];
        int b1=I[0][1];

        matrix_exp(m-2);    //a2f2 + b2f1= y;
        int a2=I[0][0];
        int b2=I[0][1];
    
        int z1=lcm(a1,a2)/a1;
        a1*=z1;
        b1*=z1;     x*=z1;

        int z2=lcm(a1,a2)/a2;
        a2*=z2;
        b2*=z2;     y*=z2;

        int dif_b=b2-b1;
        int dif_x_y=y-x;
        if(dif_b<0){
            dif_b*=-1;
            dif_x_y*=-1;
        }
        if(dif_x_y<=0){flag=0;}
        if(dif_x_y%dif_b){flag=0;}
        f1=dif_x_y/dif_b; 
        f2=(x-(b1*f1));
        if(f2<=0){flag=0;}
        if(f2%a1){flag=0;}
        f2/=a1;
    }
    else{
        f1=x;
        matrix_exp(m-2);     //a2f2 + b2f1= y;
        int a2=I[0][0];
        int b2=I[0][1];
        f2=(y-(b2*f1));
        if(f2<=0){flag=0;}
        if(f2%a2){flag=0;}
        f2/=a2;
    }

    if((2*f1)<f2 || f2<f1 || flag==0){cout<<"Impossible"<<endl;}
    else if(k==1){cout<<f1<<endl;}
    else if(k==2){cout<<f2<<endl;}
    else{
        matrix_exp(k-2);
        int ans=(((I[0][0]*f2)%M) + ((I[0][1]*f1)%M))%M;
        cout<<ans<<endl;
    }

}   



int32_t main(){
    //war();
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