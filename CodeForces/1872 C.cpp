#include<bits/stdc++.h>


#define war() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;


int main(){
    int t;  cin>>t;
    while(t--){
        int l,r;    cin>>l>>r;
        if(r<4){            cout<<"-1\n";       continue;}
        else if(r-l>0){
            if(r%2==0){     cout<<r-2<<" 2\n";    continue;}
            else{   r--;    cout<<r-2<<" 2\n";    continue;}
        }
        else{
            if(r%2==0){     cout<<r-2<<" 2\n";    continue;}
            else{
                int sq=sqrt(r);int ok=0;    bool zzzz=1;
                
                for(int i=2;i<=sq;i++){
                    if(r%i==0){ ok=i;   zzzz=0;   break;}}
                    
                if(zzzz==1){cout<<"-1\n";}
                else{   cout<<ok<<" "<<r-ok<<"\n";}
            }
        }
    }
return 0;
}