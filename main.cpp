#include "bits/stdc++.h"
using namespace std;
const int mx=1e6+123;
bitset<mx>vis;

void sieve()
{
    for(int i=3;i*i<mx;i+=2)
        if(!vis[i])
            for(int j=i*i;j<mx;j+=2*i)
                vis[j]=1;
}

int main()
{
    sieve();
    int n;
    while(cin >> n and n>0)
    {
        for(int i=3;i<=n;i+=2)
            if(!vis[i] and !vis[n-i])
            {
                cout << n << " = ";
                cout << i << " + " << n-i << endl;
                break;
            }
    }
    return 0;
}