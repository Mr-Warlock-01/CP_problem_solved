#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N=2e3;
    vector<bool>p(N,1);
    p[0]=0;
    for(long long int i=2;i*i<N;i++)
    {
        if(p[i]!=0)
        {
            for(long long int j=i*i;j<N;j=j+i)
            {
                p[j]=0;
            }
        }
    }

    string s;
    while(cin>>s)
    {
        long long sum=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>=65 && s[i]<=90)
            {
                sum+=s[i]-65+27;
            }
            else if(s[i]>=97 && s[i]<=122)
            {
                sum+=s[i]-97+1;
            }
        }
        if(p[sum]==1)
        {
            cout<<"It is a prime word."<<endl;
        }
        else
        {
            cout<<"It is not a prime word."<<endl;
        }
    }

}