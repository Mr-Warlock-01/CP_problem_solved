#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if((n<3 || n>50)){
        return 0;
    }
    if((m<3 || m>50)){
        return 0;
    }
    if(n%2==0){
        return 0;
    }


    int x=2;
    for(int i=2; i<(n+2); i++){
        if (i%2==0){
            for(int j=0; j<m; j++){
                cout<<"#";
            }
            cout<<"\n";
        }
        else{
            if(x%2==0){
                for(int j=0; j<(m-1); j++){
                cout<<".";
                }
                cout<<"#\n";
            }
            else{
                cout<<"#";
                for(int j=0; j<(m-1); j++){
                cout<<".";
                }
                cout<<"\n";
            }
            x++;
        }

    }






return 0;
}