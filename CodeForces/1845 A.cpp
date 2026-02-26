#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){      //a coins of  n, b coins of 1
    //war();
    int t;  cin>>t;
    while(t--){
        int n,k,x;
        cin>>n>>k>>x;
        if(n<=k and n!=x){
            cout<<"YES\n"<<"1\n"<<n<<"\n";
        }
       else if(x==1){
            if(n%2==1 & k>=3){
                cout<<"YES\n";
                n-=3;
                int z=n/2;
                cout<<z+1<<"\n"<<"3 ";
                for(int i=0; i<z; i++){
                    cout<<"2 ";
                }
                cout<<"\n";
            }

            else if(n%2==0 & k>=2){
                int z=n/2;
                cout<<"YES\n"<<z<<"\n";
                for(int i=0; i<z; i++){
                    cout<<"2 ";
                }
                cout<<"\n";
            }
            else{cout<<"NO\n";}
        }
        
        else{
            cout<<"YES\n"<<n<<"\n";
            for(int i=0;i<n; i++){
                cout<<"1 ";
            }
            cout<<"\n";
        }




    }
return 0;
}