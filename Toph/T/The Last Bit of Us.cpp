// https://toph.co/arena?practice=68221ee6cd5da81ac2a196f9#!/p/681cf1d475e9694df049b345

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl "\n"
#define all(x) x.begin(), x.end()
#define pb push_back

const int N=3e5+7;

vector<int>graph[N];
bool arr[N];
int ans;


bool dfs(int x, int par){
	bool cur=arr[x];
	for( auto u: graph[x]){
		if(u!=par){
			cur^=dfs(u, x);
		}
	}
	if(cur==1){ans++;}
	return cur;
}



void clear_kori(int n){
	for(int i=0; i<=n; i++){
		graph[i].clear();
	}
}

void solve(int testcase){
	int n;	cin>>n;
	clear_kori(n+3);
	for(int i=1; i<=n; i++){cin>>arr[i];}

	for(int i=1; i<n; i++){
		int u,v;	cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	int one_cnt=0;
	for(int i=1; i<=n; i++){
		if(arr[i]==1){one_cnt++;}
	}

	if(one_cnt&1){cout<<"-1"<<endl; return;}
	ans=0;
	dfs(1, -1);
	cout<<ans<<endl;
}






int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t=1;
	cin >> t;
	for(int i=1; i<=t; i++){
		solve(i);
	}
	
	return 0;
}