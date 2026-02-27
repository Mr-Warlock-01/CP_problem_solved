#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;      cin>>t;
    for(int tc=0; tc<t; tc++){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int grp=0;
        int x=arr[0];
        for(int i=0; i<n; i++){
            x&=arr[i];
            if(x==0){
                grp++;
                if(i==(n-1)){
                    break;
                }
                x=arr[i+1];
            }
        }
        if(grp==0){
            cout<<1<<"\n";
        }
        else{
            cout<<grp<<"\n";
        }
    }
return 0;
}