#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
    int a,b,c,d,e;  cin>>a>>b>>c>>d>>e;
    int sum=a+b+c+d+e;
    int z=sum/5;
    int ok=z*5;

    if(ok==sum & sum !=0){
        cout<<z;
    }
    else{cout<<"-1";}

return 0;
}