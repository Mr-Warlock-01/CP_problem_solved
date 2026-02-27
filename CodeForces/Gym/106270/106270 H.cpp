#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;




using namespace __gnu_pbds;

template<typename T> using o_set  = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

#define int ll

#define pb push_back
const ll mod = 1e9 + 7;

// inline void normal(ll &a, ll MOD){a %= MOD; (a < 0) && (a+=MOD); }
// inline ll modMul(ll a, ll b, ll MOD){ a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); return(a*b)%MOD;}
// inline ll modAdd(ll a, ll b, ll MOD){ a %= MOD, b %= MOD; normal(a, MOD), normal(b, MOD); return(a+b)%MOD;}
// inline ll modSub(ll a, ll b, ll MOD){ a%= MOD, b%=MOD; normal(a, MOD), normal(b, MOD); a-=b; normal(a, MOD); return a;}
// inline ll modPow(ll b, ll p, ll MOD){ll r = 1; while(p) { if (p&1) r = modMul(r, b, MOD); b = modMul(b, b, MOD); p >>= 1;} return r;}
// inline ll modInverse(ll a, ll MOD){ return modPow(a, MOD-2, MOD);}
// inline ll modDiv(ll a, ll b, ll MOD){ return modMul(a, modInverse(b, MOD), MOD);}

const int N=1e6+7;

int odd_free[N],even_free[N];


void pre_cal(){
	vector<int>v(N);
	for(int i=1; i<N; i++){v[i]=i;}

	for(int i=2; i<N; i++){
		if(v[i]==i){
			for(int j=i; j<N; j+=i){
				int cnt=0;
				while(v[j]%i==0){
					v[j]/=i;
					cnt++;
				}
				if(i%2==0){
					even_free[j]+=(cnt*i);
				}
				else{
					odd_free[j]+=(cnt*i);
				}
			}
		}
	}

	for(int i=1; i<N; i++){
		if(v[i]!=1){
			if(v[i]%2==0){
				even_free[i]+=v[i];
			}
			else{
				odd_free[i]+=v[i];
			}
		}
	}
}


void solve(int test){
	int n,x,y; cin>>n>>x>>y;
	vector<int>aa,bb;
	for(int i=0; i<n; i++){
		int val;	cin>>val;
		aa.pb(even_free[val]);
		bb.pb(odd_free[val]);
	}

	int ans=0;
	for(int i=0; i<n; i++){
		ans+=bb[i];
	}

	vector<int>zzz;
	for(int i=0; i<n; i++){
		zzz.pb(aa[i]-bb[i]);
	}

	sort(zzz.begin(),zzz.end());

	for(int i=0; i<y; i++){
		ans+=zzz[i];
	}

	int temp=ans;

	for(int i=y; i<n-x; i++){
		temp+=zzz[i];
		ans=min(temp,ans);
	}
	cout<<ans<<endl;

}

signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1;
	cin >> t;
	pre_cal();
	for(int i=1; i<=t; i++){
		solve(i);
	}
	return 0;
}