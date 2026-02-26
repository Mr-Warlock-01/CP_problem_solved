#include <iostream>
using namespace std;
int main(){
    int n;
    int z=0;
    int f1,f2,f3;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>f1;
        cin>>f2;
        cin>>f3;

        if((f1+f2+f3)>=2){
            z++;
        }
        else{
            continue;
        }
    }
    cout<<z;


}