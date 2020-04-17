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

class graph{
public:
int v;
list <int>* adj;
//like giving array name  int* A; A=new int[6];

graph(int a)
{
    v=a;
    adj=new list <int> [v];
}
void add_edge(int a,int b)
{
    adj[a].pb(b);
    adj[b].pb(a);
}

};


void BFS(graph G,int s,bool visited[])
{
    queue<int> Q;
    //Q cotain vertex that is still top be explored
    Q.push(s);
    //bool visited[G.v]={false};
    //cout<<"Visiting "<<s<<endl;
    visited[s]=true;

    while(!Q.empty())
    {
        int explore=Q.front();
        Q.pop();
        for(auto i=G.adj[explore].begin();i!=G.adj[explore].end();i++)
        {
            if(visited[*i]==false){
            //cout<<"Visiting "<<(*i)<<endl;
            visited[*i]=true;
            Q.push(*i);
            }

        }

    }
    return;
}

int main(){

 int T;
 cin>>T;
 while(T--)
 {
     int vv;
     //cout<<"Enter total vertices\n";
     cin>>vv;
     graph G(vv);
     int n;
     //cout<<"eter total edges\n";
     cin>>n;
     f(i,0,n)
     {
         int a,b;
         cin>>a>>b;
         G.add_edge(a,b);
     }
     int ans=0;
     bool visited[vv]={false};
     f(i,0,vv){
         if(visited[i]==false){
     BFS(G,i,visited);
     //cout<<endl;
     ans++;
         }
     }
     cout<<ans<<endl;
 }

return 0;
}
