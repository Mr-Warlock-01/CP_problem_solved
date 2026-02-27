#include <bits/stdc++.h>
using namespace std;
int main(){
    int y;
    cin>>y;

    if(y>9000 || y<1000){
        return 0;
    }
    int arr[4];
    int x;
    for(int i=0; i<200 ;i++){
        y++;
        x=y;
        arr[3]=x%10;
        x=x/10;
        arr[2]=x%10;
        x=x/10;
        arr[1]=x%10;
        x=x/10;
        arr[0]=x%10;

        if(arr[0]==arr[1]){
            continue;
        }
        else if(arr[0]==arr[2]){
            continue;
        }
         else if(arr[0]==arr[3]){
            continue;
        }
         else if(arr[1]==arr[2]){
            continue;
        }
         else if(arr[1]==arr[3]){
            continue;
        }
         else if(arr[2]==arr[3]){
            continue;
        }
        else{
            break;
        }
    }

    for(int i=0;i<4;i++){
        cout<<arr[i];
    }



return 0;
}