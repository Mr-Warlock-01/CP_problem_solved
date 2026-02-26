#include<bits/stdc++.h>
using namespace std;
signed main(){
    int t;      cin>>t;
    for(int tc=0; tc<t; tc++){
        int x,y,z;  cin>>x>>y>>z;
        if(z>45){
            cout<<"-1\n";
            continue;
        }
        int arr[z];     arr[0]=x;   arr[z-1]=y;
        int dif=0;
        for(int i=z-2; i>0; i--){
            dif++;
            arr[i]=arr[i+1]-dif;
        }
        dif++;
        if(dif > (arr[1]-arr[0])){
            cout<<"-1\n";
        }
        else{
            for(int i=0; i<z; i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }

    }
return 0;
}