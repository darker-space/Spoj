#include <iostream>
#include<stdio.h>
#include<string>
#include<set>
#include<cmath>
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


int main()
{
    fast;
      int n,k,c;
      cin>>n>>k>>c;
      int A[n];
      deque <int>Q;
      deque <int>Q2;
     f(i,0,n){
     cin>>A[i];
    }
    f(i,0,k)
    {
        while(!Q.empty()&&A[Q.back()]<A[i])//dont put =....wrong ans
            Q.pop_back();
        Q.push_back(i);
        while(!Q2.empty()&&A[Q2.back()]>A[i])//dont put =....wrong ans
            Q2.pop_back();
        Q2.push_back(i);
    }

        vector <int> ans;
 for(int i=k;i<n;i++)
 {
     if((A[Q.front()]-A[Q2.front()])<=c)
     ans.pb(i-k+1);
   while(!Q.empty()&&Q.front()<(i-k+1))
    Q.pop_front();
   while(!Q.empty()&&A[Q.back()]<A[i])//dont put =....wrong ans
            Q.pop_back();
        Q.push_back(i);

   while(!Q2.empty()&&Q2.front()<(i-k+1))
    Q2.pop_front();
   while(!Q2.empty()&&A[Q2.back()]>A[i])//dont put =....wrong ans
            Q2.pop_back();
        Q2.push_back(i);
  }
   if((A[Q.front()]-A[Q2.front()])<=c)
     ans.pb(n-k+1);

  if(ans.size()==0)
    cout<<"NONE\n";
  else{
  for(auto &x:ans)
    cout<<x<<endl;
  }
    return 0;

}
