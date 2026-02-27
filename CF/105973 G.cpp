#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) x.begin(), x.end() 
typedef long long int ll;
#define int  long long

// const int mod = 1e7 + 7;

// inline void normal(ll &a, ll MOD) { a%=MOD; (a<0) && (a += MOD);}
// inline ll modMul(ll a, ll b, ll MOD){ a%=MOD, b%=MOD; normal(a, MOD), normal(b, MOD), return(a*b)%MOD;}
// inline ll modAdd(ll a, ll b, ll MOD){} 

const int N=1e6+9;

int arr[N];
vector<int>graph[N];
int dp[N];
int n;	
int t[4 * N];


void build(int v, int l, int r){
	if(l==r) {
		t[v] = arr[l];
		return;
	}
	int mid = (l+r) >> 1;
	build(2*v, l, mid);
	build(2*v+1,mid+1, r);
	t[v] = max(t[2*v], t[2*v+1]);
}
int maxQ(int v, int L, int R, int l, int r){
	if(L>r or R<l) return -1;
	if(L>=l and R<=r) return t[v];
	int mid = (L+R) >> 1;
	int left = maxQ(2*v, L, mid, l,r);
	int right = maxQ(2*v+1, mid+1, R, l, r);
	return max(left, right);
}


int bs(int i, int val){
	int ans=n;
	int l=0, r=graph[i].size()-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(graph[i][mid]>val){ans=graph[i][mid]; r=mid-1;}
		else{l=mid+1;}
	}
	return ans;
}


int xxx(int pos, int val){
	if(pos==n){return 0;}
	if(dp[pos]!=-1){return dp[pos];}
	int idx=bs(val, pos);
	int ans;
	if(idx!=n){
		int mx=maxQ(1, 0, n-1, pos, idx-1);
		if(mx>(val)){idx=n;}
	}
	ans=xxx(idx, val+1)+((idx-pos)*val);
	return dp[pos]=ans;
}

void clr(){
	for(int i=0; i<=(n+3); i++){
		graph[i].clear();
		dp[i]=-1;
	}
	
}

void solve(int testcase){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	clr();
	build(1, 0, n-1);
	for(int i=0; i<n; i++){
		graph[arr[i]].push_back(i);
	}


	int ans=0;

	for(int i=0; i<graph[0].size(); i++){
		ans+=xxx(graph[0][i], 1);
	}
	cout<<ans<<endl;


}

signed main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t=1;
	cin >> t;
	for(int i=1; i<=t; i++){
		solve(i);
	}
}