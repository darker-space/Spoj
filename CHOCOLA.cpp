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

class str{
    public:
    ll ff;
    ll ss;
    int nn;

   void strr(ll a,ll b,int c)
    {
        ff=a; ss=b; nn=c;
    }
};

ll t[102][102],r[102][102];

str DP[105][255];

str dp(int n,int i,int T)
{
    if(i==n-1||T<=0){
         str k;
         k.strr(0,0,i);

         return k;
         }

    if(DP[i][T].ff!=-1)
        return DP[i][T];

    //cout<<"i= "<<i<<" T= "<<T<<endl;
       str res;
       res.strr(9999999,0,i);
        ll ii=0;
    f(j,i+1,n)
    {
        //cout<<"loop of i= "<<i<<" j= "<<j<<" T= "<<T<<endl;
        if(t[i][j]<=T){
       str p= dp(n,j,T-t[i][j]);
       p.ff+=r[i][j];
       p.ss+=t[i][j];
       //cout<<" res from i="<<i<<" j="<<j<<"  p.ff="<<p.ff<<" p.ss="<<p.ss<<endl;
       if (res.ff==9999999||p.nn==n-1)
        {
            if(p.ff<res.ff)
            res=p;
        }
        }

    }

    return DP[i][T]=res;

}

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
      int n,m;
      cin>>m>>n;
      m--;
      n--;
      multimap <int,int> M;
      int A[n+m];
      f(i,0,m)
      {
          cin>>A[i];
          M.insert(mp(A[i],1));
      }
      f(i,m,n+m)
      {
          cin>>A[i];
          M.insert(mp(A[i],2));
      }
      int x=0,y=0;

      ll cost=0;
       sort(A,A+n+m);
       for(int i=n+m-1;i>=0;i--)
       {
          auto itr= M.find(A[i]);
           if(itr->ss==1)
           {
              y++;
              cost+=A[i]*(x+1);
              M.erase(itr);
           }
           else{
                x++;
             cost+=A[i]*(y+1);
              M.erase(itr);
           }
       }

       cout<<cost<<endl;

  }
    return 0;
}
