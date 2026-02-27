#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;  //passengers
        int m;  //steps
        int k;  //step height
        int H;  //vlad height
        cin>>n>>m>>k>>H;
        int h[n]; //height of i th person
        int total=0;

        for(int j=0; j<n; j++){
            cin>>h[j];
        }

        for(int j=0; j<n; j++){
            int z=H-h[j];
            if(z==0){
                continue;
            }
            if(z<0){
                z=(z*(-1));
            }
            if((z%k==0)& ((z/k)<m)){
                total++;
            }
        }
        cout<<total<<"\n";




    }

return 0;
}