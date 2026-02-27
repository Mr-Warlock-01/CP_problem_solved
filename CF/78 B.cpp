#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    int n;  cin>>n;
    for(int i=1; i<=n; i++){
        if(i==n){
            cout<<"V";
        }
        else if(i==(n-1)){
            cout<<"I";
        }
        else if(i==(n-2)){
            cout<<"B";
        }
        else if(i%4==0){
            cout<<"G";
        }
        else if(i%4==3){
            cout<<"Y";
        }
        else if(i%4==2){
            cout<<"O";
        }
        else if(i%4==1){
            cout<<"R";
        }
    }

return 0;
}