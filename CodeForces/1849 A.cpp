#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int b,c,h;
        cin>>b>>c>>h;
        int z = min(b-1,c+h);
        cout<<(z*2)+1<<endl;
    }


return 0;
}