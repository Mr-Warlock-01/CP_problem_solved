#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        char arr[10][10];
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cin>>arr[i][j];
            }
        }
        int ans=0;

        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(arr[i][j]=='.'){
                    continue;
                }
                else{
                    if(i==0 || i==9 || j==0 || j==9){
                        ans++;
                    }
                    else if((i==1 || i==8) &(j>0 & j<9)){
                        ans=ans+2;
                    }
                    else if((j==1 || j==8) &(i>0 & i<9)){
                        ans=ans+2;
                    }
                    else if((i==2 || i==7) & (j>0 & j<9)){
                        ans=ans+3;
                    }
                    else if((j==2 || j==7) & (i>0 & i<9)){
                        ans=ans+3;
                    }
                    else if((i==4 & j==4) || (i==5 & j==5) || (i==5 & j==4) || (i==4 & j==5)){
                        ans=ans+5;
                    }
                    else{
                        ans=ans+4;
                    }
                }

            }
        }
        cout<<ans<<endl;
    }







return 0;
}