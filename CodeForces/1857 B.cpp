#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int tc=0; tc<t; tc++){
        string num;
        cin>>num;
        int len = num.length();
        int zzz=NULL;
        bool a=false;
        for(int i=0; i<len; i++){
            if(num[i]>'4'){
                zzz=i;
                a=true;
                break;
            }
        }
        if(a==false){
            cout<<num<<"\n";
        }
        else{
            for(int i=zzz; i>0; i--){
            if(num[i]>'4'){
                num[i]='0';
                num[i-1]+=1;
            }
        }
            if(num[0]>='5'){
                cout<<"10";
                for(int i=1; i<=zzz; i++){
                    cout<<num[i];
                }
                int ok=len-(zzz+1);
                for(int i=0; i<ok; i++){
                    cout<<'0';
                }
                cout<<"\n";
            }
            else{
                for(int i=0; i<=zzz; i++){
                    cout<<num[i];
                }
                int ok=len-(zzz+1);
                for(int i=0; i<ok; i++){
                    cout<<'0';
                }
                cout<<"\n";
            }

        }

    }

return 0;
}