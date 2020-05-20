#include <iostream>
#include<stdio.h>
#include<string>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
#include<typeinfo>
#include <stdlib.h>
#include<iomanip>
#include<map>
#define N 100000000
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    fast;
     ll n,k;
     cin>>n>>k;
     int A[n];
     f(i,0,n)
     cin>>A[i];
     int i=0,j=0;
     ll maxx=0,ans=0;
     while(j<n)
     {
         while(maxx+A[j]<=k)
            maxx+=A[j++];
        if(ans<maxx)
            ans=maxx;
         while(maxx+A[j]>k)
             maxx-=A[i++];

     }
     cout<<ans<<endl;


    return 0;

}
