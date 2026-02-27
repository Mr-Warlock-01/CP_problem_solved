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

const int N=3e5+3;
const int MOD=1e9+9;

pair<int,int>fib[N];
int arr[N];
int treee[4*N];
pair<int,pair<int,int>>lazy[4*N];   //rangesum*x, f1,f2

void fibonacci(){
    fib[1].ff=1;
    fib[2].ss=1;
    for(int i=3; i<N; i++){ //find fib
        fib[i].ff=(fib[i-1].ff+fib[i-2].ff)%MOD;
        fib[i].ss=(fib[i-1].ss+fib[i-2].ss)%MOD;
    }
    for(int i=1; i<N; i++){ //pre_sum
        fib[i].ff=(fib[i].ff+fib[i-1].ff)%MOD;
        fib[i].ss=(fib[i].ss+fib[i-1].ss)%MOD;
    }
}

int cal(int l, int r, int x, int y){
    l--;
    int aa = (fib[r].ff-fib[l].ff+MOD)%MOD;
    int bb = (fib[r].ss-fib[l].ss+MOD)%MOD;
    int ans1=(aa*x)%MOD;
    int ans2=(bb*y)%MOD;
    return (ans1+ans2)%MOD;
}

void build(int node, int st, int en){
    if(st==en){  treee[node] = arr[st]; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=(treee[2*node]+treee[2*node+1])%MOD;
    return;
}

void relax(int node, int st, int en, int l, int r){
    if(lazy[node].ff!=0){
        int ans=(cal(st,en, 1, 1)*lazy[node].ff)%MOD;
        treee[node]=(treee[node]+ ans)%MOD;
        if(st!=en){
            lazy[2*node].ff+=lazy[node].ff;
            lazy[2*node+1].ff+=lazy[node].ff;
        }
        lazy[node].ff=0;
    }

    if(lazy[node].ss.ff!=0 || lazy[node].ss.ss!=0){
        int ans=cal(1, en-st+1, lazy[node].ss.ff, lazy[node].ss.ss);
        treee[node]=(treee[node]-ans+MOD)%MOD;
        if(st!=en){
            int mid=((en-st)/2)+st;
            int val_3=cal(mid-st+2, mid-st+2, lazy[node].ss.ff, lazy[node].ss.ss);
            int val_4=cal(mid-st+3, mid-st+3, lazy[node].ss.ff, lazy[node].ss.ss);

            lazy[2*node].ss.ff= (lazy[2*node].ss.ff+ lazy[node].ss.ff)%MOD;
            lazy[2*node].ss.ss= (lazy[2*node].ss.ss+ lazy[node].ss.ss)%MOD;
            lazy[2*node+1].ss.ff= (lazy[2*node+1].ss.ff+ val_3)%MOD;
            lazy[2*node+1].ss.ss= (lazy[2*node+1].ss.ss+ val_4)%MOD;       
        }
        lazy[node].ss.ff=0;
        lazy[node].ss.ss=0;
    }
}

int query(int node, int st, int en, int l, int r){
    relax(node, st, en, l ,r);
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    int q1= query(2*node, st, mid, l, r);
    int q2= query(2*node+1, mid+ 1, en, l, r);
    return (q1+q2)%MOD;
}


void update(int node, int st, int en, int l, int r){
    relax(node, st, en, l, r);
    int mid=((en-st)/2)+st;
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        int val_1 = (cal(st,st,1,1)- cal(st-l+1, st-l+1, 1,1)+MOD)%MOD;
        int val_2 = (cal(st+1,st+1,1,1)- cal(st-l+2, st-l+2, 1,1)+MOD)%MOD;
        int val_3 = (cal(mid+1, mid+1, 1,1) - cal(mid-l+2, mid-l+2, 1, 1)+MOD)%MOD;
        int val_4 = (cal(mid+2, mid+2, 1,1) - cal(mid-l+3, mid-l+3, 1, 1)+MOD)%MOD;
        
        treee[node]=(treee[node]+ cal(st,en,1,1))%MOD;
        treee[node]=(treee[node]- cal(1,en-st+1,val_1, val_2)+MOD)%MOD;
        if(st!=en){ 
            lazy[2*node].ff+=1;         
            lazy[2*node].ss.ff=(lazy[2*node].ss.ff+val_1)%MOD;
            lazy[2*node].ss.ss=(lazy[2*node].ss.ss+val_2)%MOD;
            lazy[2*node+1].ff+=1;
            lazy[2*node+1].ss.ff=(lazy[2*node+1].ss.ff+val_3)%MOD;
            lazy[2*node+1].ss.ss=(lazy[2*node+1].ss.ss+val_4)%MOD;
        }
        return;
    }
    update(2*node, st, mid, l, r);
    update(2*node+1, mid+1, en, l, r);
    treee[node]=(treee[2*node] + treee[2*node+1])%MOD;
    return;
}



void solve(int T){
    int n;  cin>>n;
    int q;  cin>>q;
    for(int i=1; i<=n; i++){cin>>arr[i];}

    fibonacci();
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