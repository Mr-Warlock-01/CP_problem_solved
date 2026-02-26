#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int z=s.length();
    for(int i=0; i<z;i++){
        s[i]=tolower(s[i]);
    }
    string ok;
    for(int i=0; i<z; i++){
        if(s[i]==('a') || s[i]==('o') || s[i]==('y') || s[i]==('e') || s[i]==('u') || s[i]==('i')) {
            continue;
        }
        else{
            ok+='.';
            ok+=s[i];
        }
    }
    cout<<ok;
return 0;
}
 