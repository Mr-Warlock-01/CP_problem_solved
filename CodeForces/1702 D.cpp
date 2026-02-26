#include<bits/stdc++.h>                                 //DRINK WATER

//#define int long long
//#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        string s;   int p;      cin>>s>>p;
        int z=s.length(); int sum=0;
        int arr[26];    for(int i=0; i<26; i++){arr[i]=0;}
        for(int i=0; i<z; i++){
            arr[s[i]-97]++;
            sum+=(s[i]-96);
        }
        if(sum<=p){cout<<s<<"\n"; continue;}
        for(int i=25; i>=0; ){
            if(arr[i]>0){arr[i]--; sum-=(i+1);}
            else{i--;}
            if(sum<=p){break;}
        }
        string s1="";
        for(int i=0;i<z;i++){
            if(arr[s[i]-97]>0){ s1+=s[i];   arr[s[i]-97]--;}
        }
        cout<<s1<<"\n";
    }
return 0;
}