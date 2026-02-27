#include <iostream>

using namespace std;

int main()
{
   int t;
   cin>>t;
   for(int i=0;i<t;i++)
   {
       int n;
       cin>>n;
       string s;
       cin>>s;
       int fastb=-2;
       int lastb=-1;

       for(int j=0;j<n;j++)
       {
           if(s[j]=='B')
           {
               fastb=j;
               break;
           }

       }
       for(int j=n-1;j>=0;j--)
       {
           if(s[j]=='B')
           {
               lastb=j;
               break;
           }
       }
       cout<<lastb-fastb+1<<endl;
   }
}