#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=0,b=n-1;
    int sereja=0, dima=0;

    if((n>=1)&&(n<=1000)){
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        for(int i=0; i<(n/2); i++){
            if(arr[a]>arr[b]){
                sereja=sereja +arr[a];
                a++;
            }
            else{
                sereja=sereja +arr[b];
                b--;
            }
            if(arr[a]>arr[b]){
                dima=dima +arr[a];
                a++;
            }
            else{
                dima=dima +arr[b];
                b--;
            }
        }
        if(n%2==1){
            sereja=sereja +arr[a];
        }

        cout<<sereja<<"\n";
        cout<<dima<<"\n";

    }
    return 0;
}