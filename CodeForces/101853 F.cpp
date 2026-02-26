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
        int n;  int m;
        cin>>n>>m;
        vector<string> ss;
        vector<string> ee;
        string s,e;

        int HH=0, MM=0;
        for(int i=0; i<n; i++){
            cin>>s>>e;
            ss.push_back(s);    ee.push_back(e);
        }

        for(int i=0; i<n; i++){
            int s1,s2,s3,s4,e1,e2,e3,e4;
            s1= ss[i][0]-48;
            s2= ss[i][1]-48;
            s3= ss[i][3]-48;
            s4= ss[i][4]-48;

            e1= ee[i][0]-48;
            e2= ee[i][1]-48;
            e3= ee[i][3]-48;
            e4= ee[i][4]-48;

            int hhs,hhe,mms,mme;
            int hh,mm;
            hhs=(s1*10)+s2;
            hhe=(e1*10)+e2;
            mms=(s3*10)+s4;
            mme=(e3*10)+e4;
            if(mme<mms){mme+=60;    hhs++;}
            mm=mme-mms;
            hh=hhe-hhs;
            HH+=hh;     MM+=mm;
        }
        int x=MM/60;
        HH+=x;
        if(HH>=m){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
return 0;
}