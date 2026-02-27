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
        sort(arr,arr+n);
        int ans=n;
        for(int i=n-1; i>0; i--){
            if(abs(arr[i]-arr[i-1])<arr[ans-1]){
                if(ans!=i+1){
                    i++;
                }
                ans--;
            }
        }
        cout<<ans<<endl;
    }
return 0;
}