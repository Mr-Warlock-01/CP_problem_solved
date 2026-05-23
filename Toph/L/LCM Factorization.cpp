// https://toph.co/arena?practice=68221ee6cd5da81ac2a196f9#!/p/681cf32075e9694df049b36d

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl "\n"
#define all(x) x.begin(), x.end()
#define pb push_back
#define int long long 
const int N=3e5+7;
const ll MOD=998244353;

vector<int>prime_factors[N];
int f[N];  
int cnt[N];                                                
int n,k;



ll bigMod(int x, ll n, int mod){
	ll ans = 1;
	while(n > 0){
		if(n & 1) ans = (ans * 1LL * x) % mod;
		x = (1LL * x * x )% mod;
		if( x < 0) x += mod;
		n >>= 1; 
	}
	return ans;
}

void prime_factorization(){
	for(int i=2; i<N; i++){
		if(prime_factors[i].size()>0) continue;
		for(int j=i; j<N; j+=i){
			prime_factors[j].pb(i);
		}
	}
}

void factorial(){
	f[0]=1;
	f[1]=1;
	for(int i=2; i<N; i++){
		f[i]=(f[i-1]*i*1ll)%MOD;
		if(f[i] < 0) f[i] += MOD;
	}
}


ll find_ncr(ll n, ll r){
	if(n < r) return 0;
	if(n==r) return 1;
	ll x=f[n];
	ll y=(f[n-r]*f[r])%MOD;
	y = bigMod(y, MOD-2, MOD);
	x = (x * y) % MOD;
	return x;
}




void solve(int testcase){
	cin>>n>>k;
	for(int i=0; i<=n+2; i++){cnt[i]=0;}
	int x;
	for(int i=0; i<n; i++){
		cin>>x;
		for(auto u:prime_factors[x]){cnt[u]++;}	
	}
	
	ll nCr= find_ncr(n, k);
	ll ans=0;
	for(int i=2; i<=n; i++){
		if(cnt[i]){
			ll temp=nCr - find_ncr(n - cnt[i], k);
			temp=(temp+MOD)%MOD;
			temp=(temp*i)%MOD;
			ans=(ans+temp)%MOD;
		}
	}
	cout<<ans<<endl;
}






int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int t=1;
	cin >> t;
	///////////////////
	prime_factorization();
	factorial();
	//////////////////
	for(int i=1; i<=t; i++){
		solve(i);
	}
	
	return 0;
}