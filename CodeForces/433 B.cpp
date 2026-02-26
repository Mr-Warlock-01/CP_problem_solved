#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
 
    int n;    cin>>n;
    int arr1[n],arr2[n];

    for(int i=0; i<n; i++){ cin>>arr1[i];   arr2[i]=arr1[i];}
    int t;  cin>>t;
    sort(arr2,arr2+n);
    for(int i=1;i<n;i++){
        arr1[i]=arr1[i]+arr1[i-1];
        arr2[i]=arr2[i]+arr2[i-1];
    }

    while(t--){
        int p,l,r;  cin>>p>>l>>r;
        if(p==1){
            if(l==1){cout<<arr1[r-1]<<"\n";}
            else{cout<<arr1[r-1]-arr1[l-2]<<"\n";}
        }
        else{
            if(l==1){cout<<arr2[r-1]<<"\n";}
            else{cout<<arr2[r-1]-arr2[l-2]<<"\n";}
        }
    }
return 0;
}