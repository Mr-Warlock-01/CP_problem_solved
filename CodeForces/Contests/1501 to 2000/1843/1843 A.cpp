#include<bits/stdc++.h>                                 //DRINK WATER

//#define int long long
//#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)  {cin>>arr[i];}
        sort(arr,arr+n);
        if(n<2)     {cout<<"0\n";}
        else{
            int zzz=n/2;
            int ans=0;
            for(int i=0; i<zzz; i++){
                ans+=(arr[n-(i+1)]-arr[i]);
            }
            cout<<ans<<"\n";
        }
    }
return 0;
}