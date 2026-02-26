#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
    //war();
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int arr[n-1];
        for(int i=0;i<n-1;i++){
            cin>>arr[i];
        }
        int ans[n];
        ans[0]=arr[0];

        for(int i=0; i<n-1; i++){
            ans[i+1]=arr[i];
            if(max(ans[i],ans[i+1])!=arr[i]){
                ans[i]=arr[i];
            }
        }
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
return 0;
}