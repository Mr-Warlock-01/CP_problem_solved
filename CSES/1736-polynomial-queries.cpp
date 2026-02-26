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
const ll MOD   = 1e9+7;
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


#define YES {cout<<"yes"<<endl;}
#define NO  {cout<<"no"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

#define int ll

const int N=2e5+3;
int arr[N];
int treee[4*N];
pair<int,int>lazy[4*N];   //rangesum*x, extra

int sum_l_r(int l, int r){
    int r_r=(r*(r+1))/2;
    int l_l=(l*(l-1))/2;
    return r_r - l_l;
}

void build(int node, int st, int en){
    if(st==en){  treee[node] = arr[st]; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=treee[2*node]+treee[2*node+1];
    return;
}

void relax(int node, int st, int en, int l,int r){
    if(lazy[node].ff!=0){
        treee[node]+=sum_l_r(st,en)*lazy[node].ff;
        if(st!=en){
            lazy[2*node].ff+=lazy[node].ff;
            lazy[2*node+1].ff+=lazy[node].ff;
        }
        lazy[node].ff=0;
    }

    if(lazy[node].ss!=0){
        treee[node]-=((en-st+1)*lazy[node].ss);
        if(st!=en){
            lazy[2*node].ss+=lazy[node].ss;
            lazy[2*node+1].ss+=lazy[node].ss;
        }
        lazy[node].ss=0;
    }
}

int query(int node, int st, int en, int l, int r){
    relax(node, st, en, l, r);
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    int q1= query(2*node, st, mid, l, r);
    int q2= query(2*node+1, mid+ 1, en, l, r);
    return q1+q2;
}

void update(int node, int st, int en, int l, int r){
    relax(node, st, en, l, r);
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        treee[node]+=sum_l_r(st,en)-((en-st+1)*(l-1));
        if(st!=en){
            lazy[2*node].ff+=1;     lazy[2*node].ss+=(l-1);
            lazy[2*node+1].ff+=1;   lazy[2*node+1].ss+=(l-1);  
        }
        return;
    }
    int mid=((en-st)/2)+st;
    update(2*node, st, mid, l, r);
    update(2*node+1, mid+1, en, l, r);
    treee[node]=treee[2*node] + treee[2*node+1];
    return;
}

void solve(int T){
    int n;  cin>>n;
    int q;  cin>>q;
    for(int i=1; i<=n; i++){cin>>arr[i];}

    build(1,1,n);

    while(q--){
        int x,l,r;  cin>>x>>l>>r;
        if(x==1){update(1,1,n,l,r);}
        else{cout<<query(1,1,n,l,r)<<endl;}
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