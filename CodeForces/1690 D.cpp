#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  int x,y;
  for(int l=0; l<t ;l++){
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;
    x=0,y=0;
    for (int i=0; i<k; i++){
      if(s[i]!='B'){
        x++;
      }
    }
    y=x;
    for(int i=k; i<n; i++){
      int z=i%k;
      if(s[z]=='B' & s[i]!='B'){
        y++;
      }
      else if(s[z]!='B' & s[i]=='B'){
        y--;
      }
      s[z]=s[i];
      if(y<x){
        x=y;
      }
    }
    cout<<x<<"\n";
  }

return 0;
}