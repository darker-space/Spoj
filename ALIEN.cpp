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
    int T;
    cin>>T;
    while(T--)
    {
      int n,k;
      cin>>n>>k;
      int A[n];
     f(i,0,n){
     cin>>A[i];
    }
    set <ll> a;
    map <ll,int> mp;
    ll sum=0;
    int i=0,j=0;
    while(j<n)
    {
            while(j<n&&sum+A[j]<=k){
                sum+=A[j];
                //cout<<"addind in sum "<<A[j]<<endl;
                j++;}

        //cout<<"i ="<<i<<" j="<<j<<" pushing sum= "<<sum<<endl;
        a.insert(j-i);
        if(mp[j-i]==0||mp[j-i]>sum)
        mp[j-i]=sum;
        sum-=A[i];
        i++;
        //cout<<"new sum ="<<sum<<endl;
    }
      auto itr=a.end();
      itr--;
      cout<<mp[(*itr)]<<" "<<(*itr)<<endl;
    }
    return 0;

}
