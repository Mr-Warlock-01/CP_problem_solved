#include <bits/stdc++.h>
using namespace std;


int main()
{

    int t,n[100000],ans=0;


    cin>>t;

    for(int i=0; i<t; i++)
    {
        cin>>n[i];
    }

     for(int i=0; i<t; i++)
    {    ans=n[i]+2;
        if(ans%2==0)
        {
            cout<<"2\n";
        }

        ans=n[i]+3;
        if(ans%2==0)
        {
            cout<<"3\n";
        }
    }


    return 0;
}