#include<bits/stdc++.h>


#define war() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
    int n,k;    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n; i++){
        if(arr[i]<0){
            arr[i]=abs(arr[i]);
            k--;
        }
        else{break;}
        if(k==0){break;}
    }

    if(k%2==1){
        sort(arr,arr+n);
        arr[0]=arr[0]*(-1);
    }



    int ans=0;
    for(int i=0; i<n; i++){
        ans+=arr[i];
    }
    cout<<ans;
return 0;
}