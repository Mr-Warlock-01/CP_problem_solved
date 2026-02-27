#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    war();
    int t; cin>>t;
    while(t--){
        int n;  cin>>n;
        bool ok=true;
        int arr[n];   for(int i=0; i<n; i++){   cin>>arr[i];    if(arr[i]!=0){ok=false;}}
        if(ok==1){cout<<"0\n";}
        else if(n%2==0){
            cout<<"2\n";
            cout<<"1 "<<n<<"\n";
            cout<<"1 "<<n<<"\n";
        }
        else{
            cout<<"4\n";
            cout<<"1 "<<n<<"\n";
            cout<<"1 "<<n-1<<"\n";
            cout<<n-1<<" "<<n<<"\n";
            cout<<n-1<<" "<<n<<"\n";
        }
    }
return 0;
}