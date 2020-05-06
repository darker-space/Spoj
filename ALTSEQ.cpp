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
#include<unordered_map>
#define N 100000000
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define pair_i pair<int,int>
#define read(A,n) for(ll i=0;i<n;i++) cin>>A[i]
#define pr(A,n)  for(ll i=0;i<n;i++) cout<<A[i]<<" "; cout<<endl
#define ff first
#define ss second
#define v_i vector<int>
typedef long long ll;
typedef long double ld;

using namespace std;



int main()
{


   int n;
   cin>>n;
   ll A[n],B[n];

   f(i,0,n)
   {
       cin>>A[i];
       if(A[i]<0)
        B[i]=-1;
       else
        B[i]=1;
       A[i]=abs(A[i]);
   }

     ll DP[n];

     f(i,0,n)
     DP[i]=1;

     f(i,1,n)
     {
         f_(j,i-1,0)
         {
             if(A[j]<A[i]&&(B[i]*B[j]<0))
             {
                 DP[i]=max(DP[i],DP[j]+1);
             }
         }
     }
      //pr(DP,n);
      ll maxx=0;
      f(i,0,n)
      {
          if(maxx<DP[i])
            maxx=DP[i];
      }
     cout<<maxx<<endl;



    return 0;
}
