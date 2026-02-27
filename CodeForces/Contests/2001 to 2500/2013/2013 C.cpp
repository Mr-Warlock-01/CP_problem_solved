#include<bits/stdc++.h>
using namespace std;

void pikachu(int T){         ///MAIN  (DRINK WATER)
    int n;  cin>>n;
    string s="";
    bool flag_1=0, flag_2=0;
    for(int i=0; i<(2*n); i++){
        if(s.size()==n){break;}
             if((flag_1==0) && (flag_2==0)){cout<<"? "<<s<<"0"<<endl;}
        else if((flag_1==0) && (flag_2==1)){cout<<"? "<<s<<"1"<<endl;}
        else if((flag_1==1) && (flag_2==0)){cout<<"? "<<"0"<<s<<endl;}
        bool x; cin>>x;
        if(x==0){
                 if((flag_1==0) && (flag_2==0)){flag_2=1;}
            else if((flag_1==0) && (flag_2==1)){flag_1=1;   flag_2=0;}
            else if((flag_1==1) && (flag_2==0)){s="1"+s;    flag_2=0;}
        }
        else{
                 if((flag_1==0) && (flag_2==0)){s=s+"0";}
            else if((flag_1==0) && (flag_2==1)){s=s+"1";}
            else if((flag_1==1) && (flag_2==0)){s="0"+s;}
            flag_2=0;
        }
    }

    cout<<"! "<<s<<endl;
}




signed main(){
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        pikachu(T);
    }
return 0;
}