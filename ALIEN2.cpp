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
typedef long long ll;
typedef long double ld;

using namespace std;

//pair_i dp(int X[],int y[],int n,int W)//ff-station ss -people
//{
//    if(n==0||W==0)
//        return mp(n+1,0);
//    if(X[n-1]<=W)
//    {
//        if(X[n-1]+y[n-1]<=W)
//            return min(mp(dp(X,y,n-1,W-X[n-1]).ff,dp(X,y,n-1,W-X[n-1]).ss+X[n-1]),mp(dp(y,X,n-1,W-X[n-1]-y[n-1]).ff,dp(y,X,n-1,W-X[n-1]-y[n-1]).ss+X[n-1]+y[n-1]));
//
//        else
//            return mp(dp(X,y,n-1,W-X[n-1]).ff,dp(X,y,n-1,W-X[n-1]).ss+X[n-1]);
//    }
//    else
//        return mp(n+1,0);
//
//}

pair_i DP[1001][65001];

pair_i dp(int X[],int y[],int n,int W)//ff-station ss -people
{
    if(n==0||W==0)
        return DP[n][W]=mp(n+1,0);
    if(DP[n][W].ff!=-1)
        return DP[n][W];
    if(X[n-1]<=W)
    {
        if(X[n-1]+y[n-1]<=W)
            return DP[n][W]=min(mp(dp(X,y,n-1,W-X[n-1]).ff,dp(X,y,n-1,W-X[n-1]).ss+X[n-1]),mp(dp(y,X,n-1,W-X[n-1]-y[n-1]).ff,dp(y,X,n-1,W-X[n-1]-y[n-1]).ss+X[n-1]+y[n-1]));

        else
            return DP[n][W]=mp(dp(X,y,n-1,W-X[n-1]).ff,dp(X,y,n-1,W-X[n-1]).ss+X[n-1]);
    }
    else
        return DP[n][W]=mp(n+1,0);

}

int main()
{
    fast;


      int n,W;
      cin>>n>>W;
      int A[n],B[n];
      for(int i=n-1;i>=0;i--)
       cin>>A[i];
       for(int i=n-1;i>=0;i--)
       cin>>B[i];

       f(i,0,n+1)
       f(j,0,W+1)
         DP[i][j]=mp(-1,-1);
    pair_i p1=dp(A,B,n,W);

       f(i,0,n+1)
       f(j,0,W+1)
         DP[i][j]=mp(-1,-1);
    pair_i p2=dp(B,A,n,W);

       pair_i ans=min(p1,p2);

       cout<<1+n-ans.ff<<" "<<ans.ss<<endl;

    return 0;
}
