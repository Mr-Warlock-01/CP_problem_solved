#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    war();
    int n;  cin>>n;
    int arr[n];     for(int i=0; i<n; i++){cin>>arr[i];}
    int ans=0;
    for(int i=0; i<n; i++){
        if(i==arr[i]){
            ans++;
        }
    }
    if(ans==n){
        cout<<ans<<endl;
        return 0;
    }
    else{ans++;}

    for(int i=0;i<n-1; i++){
        if(arr[i]!=i){
            int z=arr[i];
            if(arr[z]==i){
                ans++;  break;
            }
        }
    }
    cout<<ans<<endl;

}