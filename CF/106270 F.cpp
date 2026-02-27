#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

#define endl "\n"



using namespace __gnu_pbds;

template<typename T> using o_set  = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

#define int ll

// const ll mod = 1e9 + 7;

// inline void normal(ll &a, ll MOD){a %= MOD; (a < 0) && (a+=MOD); }
// inline ll modMul(ll a, ll b, ll MOD){ a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); return(a*b)%MOD;}
// inline ll modAdd(ll a, ll b, ll MOD){ a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); return(a+b)%MOD;}
// inline ll modSub(ll a, ll b, ll MOD){ a%= MOD, b%=MOD; normal(a, MOD), normal(b, MOD); a-=b; normal(a, MOD); return a;}
// inline ll modPow(ll b, ll p, ll MOD){ll r = 1; while(p) { if (p&1) r = modMul(r, b, MOD); b = modMul(b, b, MOD); p >>= 1;} return r;}
// inline ll modInverse(ll a, ll MOD){ return modPow(a, MOD-2, MOD);}
// inline ll modDiv(ll a, ll b, ll MOD){ return modMul(a, modInverse(b, MOD), MOD);}


void solve(int test){
	int length,velocity,time,n;
	cin>>length>>velocity>>time>>n;
	for(int i=0; i<n; i++){
		int tt, vv;		cin>>tt>>vv;
		int dis=velocity-vv;
		//cout<<"dis "<<dis<<endl;
		if(dis<0){dis*=-1;}
		int time_rem=time-tt;
		int ans=(time_rem*dis)/length;
		ans++;
		if(i!=0){
			cout<<" ";
		}
		cout<<ans;
	}
	cout<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1;
	cin >> t;
	for(int i=1; i<=t; i++){
		solve(i);
	}
	return 0;
}