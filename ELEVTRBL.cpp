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


int BFS(int f,int s,int dd,int u,int d)
{
    int vis[f]={0};
    vis[s]=1;
    queue<int> Q;
    Q.push(s);
    int nxt_lvl=0,prev_lvl=1,ct=0,kk=0;
    while(!Q.empty())
    {
        int exp=Q.front();
        //cout<<exp<<endl;
        Q.pop();
        if(exp==dd){
                kk=1;
            break;
        }
        prev_lvl--;
        if(exp+u<f&&vis[exp+u]==0)
        {
            vis[exp+u]=1;
             Q.push(exp+u);
             nxt_lvl++;
        }
            if(exp-d>=0&&vis[exp-d]==0)
          {
            vis[exp-d]=1;
             Q.push(exp-d);
             nxt_lvl++;
           }
        if(prev_lvl==0)
        {
            prev_lvl=nxt_lvl;
            nxt_lvl=0;
            ct++;
        }

    }
    if(kk==1)
   return ct;
    else
        return -1;
}

int main()
{

        int f,s,d,u,dd;
        cin>>f>>s>>dd>>u>>d;
       int k=BFS(f,s-1,dd-1,u,d);
       if(k==-1)
        cout<<"use the stairs\n";
       else
        cout<<k<<endl;
    return 0;
}
