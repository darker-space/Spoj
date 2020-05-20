#include <iostream>
#include<stdio.h>
#include<string>
#include<list>
#include<set>
#include<cmath>
#include<cstring>
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
#define f(i,a,b) for(ll  i=a;i<b;i++)
#define f_(i,a,b) for(ll  i=a;i>=b;i--)
#define T_ ll T; cin>>T; while(T--)
#define fast         ios_base::sync_with_stdio(false); cin.tie(NUll )
#define pb push_back
#define mp make_pair
#define pair_i pair<int,int>
#define read(A,n) for(ll  i=0;i<n;i++) cin>>A[i]
#define pr(A,n)  for(ll  i=0;i<n;i++) cout<<A[i]<<" "; cout<<endl
#define ff first
#define ss second
#define v_i vector<int>
#define map_ii map<pair<int,int>,int>
typedef long long ll ;
typedef long double ld;

using namespace std;

pair_i parent[1001][1001];
int rankk[1001][1001];
pair_i par(pair_i p1);

void unionn(int a,int b,int c,int d)
{


     pair_i p1=par(mp(a,b));
     pair_i p2=par(mp(c,d));
     if(p1==p2)
        return;

     if(rankk[p1.ff][p1.ss]>=rankk[p2.ff][p2.ss]){
        if(rankk[p1.ff][p1.ss]==rankk[p2.ff][p2.ss])
            rankk[p1.ff][p1.ss]=1+rankk[p2.ff][p2.ss];
         parent[p2.ff][p2.ss]= p1;
     }

     else{
        parent[p1.ff][p1.ss]=p2;

     }

}

pair_i par(pair_i p1)
{
    if(parent[p1.ff][p1.ss]==p1)
        return p1;
    pair_i pp=par(parent[p1.ff][p1.ss]);

    return parent[p1.ff][p1.ss]=pp;
}


int main()
{
    int n,m;
    cin>>n>>m;
    f(i,0,n)
     f(j,0,m)
      parent[i][j]=mp(i,j);


    string M[n];
    f(i,0,n)
      cin>>M[i];
    bool vis[n][m];
    memset(vis,0,sizeof(vis));


    f(i2,0,n)
     f(j2,0,m)
     {
         //cout<<"ii "<<i2<<" jj "<<j2<<endl;
         int i=i2,j=j2;
         if(vis[i][j]==0){
         int a=0,b=0;

          while(1){


             vis[i][j]=true;


             //cout<<"i"<<i<<" j"<<j<<" "<<M[i][j]<<endl;
            a=0; b=0;
         if(M[i][j]=='N')
            a=-1;
         else if(M[i][j]=='S')
            a=1;
         else if(M[i][j]=='E')
            b=1;
         else if(M[i][j]=='W')
            b=-1;
            //cout<<"i= "<<i<<" j= "<<j<<" a= "<<a<<" b= "<<b<<endl;
            if(i+a<0||i+a>=n||j+b<0||j+b>=m){
                   // cout<<".;.;.;.;";
                break;
            }

            unionn(i,j,i+a,j+b);
            i+=a;
            j+=b;
            if(vis[i][j]==1)
                break;

         }


         }

     }


     set<pair_i> S;
f(i,0,n)
     f(j,0,m)
     par(mp(i,j));

   f(i,0,n)
     f(j,0,m)
       S.insert(par(mp(i,j)));

       cout<<S.size()<<endl;

   return 0;
}
