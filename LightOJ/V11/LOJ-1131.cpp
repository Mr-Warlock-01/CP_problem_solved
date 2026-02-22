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
int N=6;

vector<vector<int>> matrix_mul(vector<vector<int>>&P1, vector<vector<int>>&P2, int a, int b_c, int d, int M){   //remove & if need
    vector<vector<int>>res(N, vector<int>(N));
    for(int i=0; i<a; i++){
        for(int j=0; j<d; j++){
            ll ans=0;
            for(int k=0; k<b_c; k++){
                ans= (ans + ((1ll*P1[i][k] * P2[k][j])%M))%M;
            }
            res[i][j]=ans;
        }
    }
    return res; 
}

vector<vector<int>> matrix_pow(vector<vector<int>>&P, ll n, int sz, ll M){   //remove & if need
    vector<vector<int>>I(N,vector<int>(N));
    for(int i=0; i<sz; i++){I[i][i]=1;}
    while(n){
        if(n&1){
            I=matrix_mul(I,P,sz,sz,sz,M);
        }
            P=matrix_mul(P,P,sz,sz,sz,M);
        n>>=1;
    }
    return I;
}
void solve(int T){
    int a1,a2,b1,b2,c1,c2;  cin>>a1>>b1>>c1;    cin>>a2>>b2>>c2;
    int f0,f1,f2,g0,g1,g2;  cin>>f0>>f1>>f2;    cin>>g0>>g1>>g2;
    

    cout<<"Case "<<T<<": "<<endl;
    int M;  cin>>M;
    int q;  cin>>q;
    while(q--){
        int n;  cin>>n;
        if(n==0){cout<<f0%M<<" "<<g0%M<<endl;}
        else if(n==1){cout<<f1%M<<" "<<g1%M<<endl;}
        else if(n==2){cout<<f2%M<<" "<<g2%M<<endl;}
        else{
            vector<vector<int>>Seq={{a1,0,b1,0,0,c1},
                                    {0,a2,0,b2,c2,0},
                                    {1,0,0,0,0,0},
                                    {0,1,0,0,0,0},
                                    {0,0,1,0,0,0},
                                    {0,0,0,1,0,0}};
            vector<vector<int>>Pat(N,vector<int>(N)); 
            Pat[0][0]=f2;
            Pat[1][0]=g2;
            Pat[2][0]=f1;
            Pat[3][0]=g1;
            Pat[4][0]=f0;
            Pat[5][0]=g0;

            Seq=matrix_pow(Seq, n-2, N, M); 
            Pat=matrix_mul(Seq, Pat, N, N, 1,M);
            cout<<Pat[0][0]<<" "<<Pat[1][0]<<endl;
        }
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