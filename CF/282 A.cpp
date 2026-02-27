#include <iostream>
using namespace std;
int main(){
    int x=0;
    int z=1;
    int n;
    cin>>n;
    if(n<1 || n>150){
        return 0;
    }

    for(int i=0; i<n;i++){
        string s;
        cin>>s;
        if(s=="++X" || s=="X++"){
            x++;
        }
        else if(s=="--X" || s=="X--"){
            x--;
        }
        else{
            return 0;
        }
    }
    cout<<x;
return 0;
}