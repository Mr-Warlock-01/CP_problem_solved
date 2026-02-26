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
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(arr[i]!=0){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }

return 0;
}