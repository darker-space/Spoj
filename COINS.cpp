#include <iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<set>
#include<cmath>
#include<queue>
#include<deque>
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
#define mp make_pair
#define pair_i pair<int,int>
#define read(A,n) for(ll i=0;i<n;i++) cin>>A[i]
#define ff first
#define ss second
#define v_i vector<int>
typedef long long ll;
typedef long double ld;

using namespace std;

map<int ,ll>DP;

ll dp(ll n)
{
    if(n==0)
        return 0;
        if(DP[n]!=0)
            return DP[n];
    return DP[n]=max(n,dp(n/2)+dp(n/4)+dp(n/3));
}

int main()
{

   ll n;
   while(scanf("%lld",&n)==1)
   {
       //cin>>n;

      cout<<dp(n)<<endl;
   }


    return 0;
}
