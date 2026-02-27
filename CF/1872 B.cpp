#include<bits/stdc++.h>
using namespace std;

#define ff 	first
#define ss  second
#define pb  push_back

const int INF=1e9;

void solve(){
	int n;	cin>>n;
	int ans=INF;

	for(int i=0; i<n; i++){
		int a,s;	cin>>a>>s;
		ans=min(ans,a+((s-1)/2));	
	}
	cout<<ans<<endl;
}

int32_t main(){
	int t=1;	cin>>t;
	while(t--){
		solve();
	}
return 0;
}