#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    if((n<1)||(n>100)){
        return 0;
    }
    for(int a=0; a<n; a++){
        string word;
        cin>>word;
        const char* word_s=word.c_str();

        int x=0;
        for(int i=0; word_s[i]!='\0'; i++){
            x++;
        }
        if(x>0 && x<101){
            if(x<=10){
                for(int j=0;j<x;j++){
                    cout<<word_s[j];
                }
                cout<<endl;
            }
            else{
                cout<<word_s[0]<<(x-2)<<word_s[x-1]<<endl;
            }
        }
        else{
            return 0;
        }
    }

    return 0;
}