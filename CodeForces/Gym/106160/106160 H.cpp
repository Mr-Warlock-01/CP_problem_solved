#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;

#define read()          freopen("cooling.in","r",stdin)
#define write()         freopen("cooling.out","w",stdout)

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
#define war()           ios::sync_with_stdio(0); cin.tie(0);

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
// *.find_by_order(x)
//substr
//cin.ignore();
//get<idx>(z) //tuple
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
const int N=1e5+7;
int ans=LLMax;

vector<int>graph[N];
int level[N];
int parent[N];

void dijkastra(){
    for(int i=0; i<N; i++){level[i]=LLMax;}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    level[1]=0;
    pq.push({0,1});

    while(!pq.empty()){
        auto [cost, node]=pq.top();
        pq.pop();
        if(cost!=level[node]){continue;}
        for(auto u: graph[node]){
            int new_cost=cost+1;
            if(level[u]>new_cost){
            	parent[u]=node;
                level[u]=new_cost;
                pq.push({new_cost,u});
            }
        }
    }
}

void dfs_find_min_ans(int x, int par, int lev){
	for(int u: graph[x]){
		if(u==par){continue;}
		if(level[u]==(lev+1)){
			dfs_find_min_ans(u,x,lev+1);
		}
		else if(level[u]==lev){
			ans=min(ans,(2*lev)+2);
		}
		else if(level[u]==(lev-1)){
			ans=min(ans,(2*lev)+1);
		}
	}
}

bool paye_gesi=0;
stack<int>st;

void go_to_par(int x){
	if(parent[x]!=0){
		go_to_par(parent[x]);
	}
	st.push(x);
}

void dfs(int x, int par, int lev){
	for(int u:graph[x]){
		if(paye_gesi==1){break;}
		if(u==par){continue;}
		if(level[u]==(lev+1)){
			dfs(u,x,lev+1);
		}
		else if(level[u]==lev && (ans==((2*lev)+2))){
			paye_gesi=1;
			go_to_par(u);
			break;
		}
		else if(level[u]==(lev-1) && (ans==((2*lev)+1))){
			paye_gesi=1;
			go_to_par(u);
			break;
		}
	}
	if(paye_gesi==1){
		st.push(x);
	}
}

void solve(int T){
	int n,m;	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u,v;	cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	dijkastra();

	dfs_find_min_ans(1,0,0);

	if(ans==LLMax){cout<<"impossible"; return;}
	dfs(1,0, 0);
	cout<<ans<<endl;
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
} 



int32_t main(){             //DRINK WATER
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

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/