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
typedef long long ll;
typedef long double ld;

using namespace std;

class graph
{
    public:
    int v;
    list <int>* adj;
    graph(int val)
    {
        v=val;
        adj=new list<int>[val];
    }

    void add_edge(int a,int b)
    {
        adj[a].pb(b);
        adj[b].pb(a);
    }
};

int BFS(graph G,int s,int vis[])
{
    int key=1;
   int visited[G.v]={0};
   vis[s]=1;
   visited[s]=1;
   queue<int> Q;
   Q.push(s);
   while(!Q.empty())
   {
       int explore=Q.front();
       Q.pop();
       for(auto i=G.adj[explore].begin();i!=G.adj[explore].end();i++)
       {
           if(visited[*i]==0)
           {
               vis[*i]=1;
               if(visited[explore]==1)
                visited[*i]=2;
               else
                visited[*i]=1;
                Q.push(*i);
           }
           else if(visited[explore]==visited[*i])
           {
               //cout<<(*i)<<" and "<<explore<<" same color\n";
               key=0;
               break;
           }}
           if(key==0)
            break;
       }
   return key;

}

int main()
{
    int T;
    cin>>T;
    f(p,0,T)
    {
        int v;
        cin>>v;
        graph G(v);
        int e;
        cin>>e;
        f(i,0,e)
        {
            int a,b;
            cin>>a>>b;
            G.add_edge(a-1,b-1);
        }
        cout<<"Scenario #"<<p+1<<":\n";
        int key=1;
        int vis[v]={0};
        f(i,0,v){
        if(vis[i]==0&&BFS(G,i,vis)==0)
        {
            key=0;
            break;
        }
        }
        if(key==0)
            cout<<"Suspicious bugs found!\n";
        else
            cout<<"No suspicious bugs found!\n";
    }
    return 0;
}
