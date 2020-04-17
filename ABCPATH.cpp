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
typedef long long ll;
typedef long double ld;

using namespace std;

char A[50][50];

int BFS(int m,int n,pair<int,int> s)
{
   int vis[m][n];
   f(i,0,m)
   f(j,0,n)
   vis[i][j]=0;

//   cout<<"visited\n";
//               f(i,0,m)
//     {
//         f(j,0,n)
//         cout<<vis[i][j];
//         cout<<endl;
//     }
   vis[s.first][s.second]=1;
   queue<pair<int,int>> Q;
   Q.push(s);
    pair<int,int> x[10]={{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,-1},{-1,1},{1,-1}};

   int pv=1,nxt=0,ct=0;
   while(!Q.empty())
   {

      pair <int,int> exp=Q.front();
       //cout<<"exploring "<<A[exp.first][exp.second]<<" "<<exp.first<<" "<<exp.second<<endl;
       Q.pop();
       pv--;
       f(i,0,8)
       {

           int a=exp.first+x[i].first;
           int b=exp.second+x[i].second;
           //cout<<"a="<<a<<" b="<<b<<" char="<<A[a][b]<<" check "<<(A[a][b]-A[exp.first][exp.second])<<" vis "<<vis[a][b]<<endl;
           if(a>=0&&a<m&&b>=0&&b<n&&vis[a][b]==0&&(A[a][b]-A[exp.first][exp.second]==1))
           {
               //cout<<"ello\n";
               vis[a][b]=1;
               Q.push(mp(a,b));
               //cout<<"pushing "<<A[a][b]<<endl;
               nxt++;
           }
       }
       if(pv==0)
       {
           pv=nxt;
           nxt=0;
           ct++;
       }
   }
   return ct;
}

int main()
{
    //fast;
    for(int ii=1;;ii++){
     int m,n;
     cin>>m>>n;
     if(m==0)
        break;
        //char A[m][n];
        vector <pair<int,int>> G;
     f(i,0,m)
     {
         f(j,0,n)
         {
             cin>>A[i][j];
             if(A[i][j]=='A')
                G.pb(mp(i,j));
         }
     }

     int maxx=0;
     f(i,0,G.size())
     {
         //cout<<"now apply bfs from "<<G[i].first<<" "<<G[i].second;
         int k=BFS(m,n,G[i]);
         if(maxx<k)
            maxx=k;
     }
     cout<<"Case "<<ii<<": "<<maxx<<endl;

    }
    return 0;
}
