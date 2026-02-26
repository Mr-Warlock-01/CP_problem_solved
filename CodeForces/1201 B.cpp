#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
    int t=1;  //cin>>t;
    while(t--){
        int n;  cin>>n;
        int a[n];
      for (int i =0; i<n; i++){
        cin>>a[i];
      }
      int sum =0;
      int large=0;
      for(int i=0; i<n; i++){
        sum+=a[i];
        large=max(large,a[i]);
      }
      if((sum%2==0) && (sum>=(2*large))){cout<<"YES"<<endl;}
      else{cout<<"NO"<<endl;}
        
return 0;
    }
}