#include <bits/stdc++.h>
using namespace std;
int main(){
    string x;
    cin>>x;
    char arr[x.length() + 1];
    strcpy(arr, x.c_str());
    int verify=1;
    for(int i=0; x.length()>i; i++){
        if(arr[i]==arr[i+1]){
            verify++;
            if(verify==7){
                cout<<"YES";
                return 0;
            }
        }
        else{
            verify=1;
        }
    }
    cout<<"NO";
return 0;
}


 