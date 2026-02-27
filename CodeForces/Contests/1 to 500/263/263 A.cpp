#include <iostream>
using namespace std;
int main(){
    int arr[5][5];
    int x,y;
    int a=0,b=0,ab=0;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(arr[i][j]==1){
                x=i;
                y=j;
                break;
            }
        }
    }

    if(x>2){
        a=x-2;
    }
    else if(x<2){
        a=2-x;
    }

    if(y>2){
        b=y-2;
    }
    else if(y<2){
        b=2-y;
    }
    ab=a+b;
    cout<<ab;

    return 0;
}