#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);



using namespace std;


signed main(){
    
    war();



    int t;  cin>>t;
    while(t--){
        int n,m;    cin>>n>>m;
        int mn=n*m;
        int arr[mn];
        for(int i=0; i<mn; i++){
            cin>>arr[i];
        }
        sort(arr,arr+mn);
        int a;      //min 1
        int b;      //max l
        int c;      //max 2
        int d;      //min 2
        a=arr[0];   b=arr[mn-1];    c=arr[mn-2];    d=arr[1];
        int ans;

        //int MA=max(n,m);
        int MI=min(n,m);

       // if(mn>4){
            int ans1=((b-a)*(mn-MI))+((c-a)*(MI-1));
            int ans2=((b-a)*(mn-MI))+((b-d)*(MI-1));
            ans=max(ans1,ans2);
        //}

        //else{ans=(3*arr[3])-arr[0]-arr[0]-arr[1];}
        cout<<ans<<"\n";
    }
return 0;
}