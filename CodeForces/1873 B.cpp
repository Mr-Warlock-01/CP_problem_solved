#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=0;
        int mul=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    mul*=(arr[j]+1);
                }
                else{
                    mul*=(arr[j]);
                }
            }
            ans=max(ans,mul);
            mul=1;
        }
        cout<<ans<<endl;

    }
return 0;
  }