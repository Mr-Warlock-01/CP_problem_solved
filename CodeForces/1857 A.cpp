#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        int arr[n];
        int z=0;
        int odd=0;
        for(int j=0; j<n; j++){
            cin>>arr[j];
            z+=arr[j];
        }
        if(z%2==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }
return 0;
}