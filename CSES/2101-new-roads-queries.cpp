#include<bits/stdc++.h>                                         //DRINK WATER
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


const int N=200009;
const int log_N=20;


pair<int,int>edge[N];
vector<pair<int,int>>graph[N];

//dsu
int parent[N];
int dsu_size[N];

//lca
pair<int,int>LCA[log_N][N];
int level[N];


int n,m,q;

int find_set(int x){
    if(x==parent[x]){return x;}
    return parent[x]= find_set(parent[x]);
}
void union_sets(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(dsu_size[a]<dsu_size[b]){swap(a,b);}
    parent[b]=a;
    dsu_size[a]+=dsu_size[b];
}
void dfs(int x, int par, int lev, int weight){
    LCA[0][x]={par,weight};
    level[x]=lev;
    for(auto [u,w]:graph[x]){
        if(par==u){continue;}
        dfs(u, x, lev+1, w);
    }
}

void lca_generate(){
    for(int i=1; i<log_N; i++){
        for(int j=1; j<=n; j++){
            int w=LCA[i-1][j].ss;
            int x=LCA[i-1][j].ff;
            if(x==-1){continue;}
            w=max(w,LCA[i-1][x].ss);
            x=LCA[i-1][x].ff;
            LCA[i][j]={x,w};
        }
    }
return;
}

int find_lac(int a, int b){
    if(level[a]>level[b]){swap(a,b);}
    int d=level[b]-level[a];
    int max_weight=0;
    while(d>0){
        int i=log2(d);
        max_weight=max(max_weight,LCA[i][b].ss);
        b=LCA[i][b].ff;
        d-=(1<<i);
    }
    if(a==b){return max_weight;}
    for(int i=log_N-1; i>=0; i--){
        if((LCA[i][a].ff!=-1) && (LCA[i][a].ff!=LCA[i][b].ff)){
            max_weight=max({max_weight, LCA[i][a].ss, LCA[i][b].ss});
            a=LCA[i][a].ff;    b=LCA[i][b].ff;
        }
    }
    return max({max_weight, LCA[0][a].ss, LCA[0][b].ss});
}




void solve(int T){            ///   (DRINK WATER)
    cin>>n>>m>>q;

    for(int i=0; i<m; i++){cin>>edge[i].ff>>edge[i].ss;}

    for(int i=0; i<=n; i++){
        parent[i]=i; 
        dsu_size[i]=1;
        level[i]=-1;
    }
    memset(LCA, -1, sizeof(LCA));

    for(int i=0; i<m; i++){
        int u=edge[i].ff; 
        int v=edge[i].ss;

        if(find_set(v) == find_set(u)){continue;}
        union_sets(v, u);
        graph[v].pb({u,i+1});
        graph[u].pb({v,i+1});
    }

    for(int i=1; i<=n; i++){
        if(level[i]==-1){dfs(i,-1, 0 , -1);}
    }

    lca_generate();

    while(q--){
        int u,v;    cin>>u>>v;
        if(find_set(u)!=find_set(v)){cout<<"-1"<<endl;}
        else{
            cout<<find_lac(u,v)<<endl;
        }
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