#include <iostream>
#include<string>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
#include<typeinfo>
#include <stdlib.h>
#include<iomanip>

typedef long long ll;

using namespace std;


int main()
{

  ll n,m;
  cin>>n>>m;
  int A[n];
  for(int i=0;i<n;i++)
    cin>>A[i];
  sort(A,A+n);
  int B[n];
  B[n-1]=A[n-1];
  for(int i=n-2;i>=0;i--)
      B[i]=A[i+1]-A[i];
      int k=2;
//      for(auto &x:B)
//        cout<<x<<" ";
//      cout<<endl;

  for(int i=n-3;i>=0;i--){
      B[i]=k*B[i]+B[i+1];
      k++;
  }

//       for(auto &x:B)
//        cout<<x<<" ";
//      cout<<endl;

   int ans=0,k2=0,ii=n-1;
   for(int i=n-2;i>=0;i--)
   {
       if(B[i]>m)
       {
           k2=1; ans=A[i+1]; ii=n-i-1; break;
       }
       else if(B[i]==m)
       {
           ans=A[i]; ii=n-i; break;
       }
   }
   //cout<<"ii= "<<ii<<" ans= "<<ans<<" k2= "<<k2<<endl;
   if(k2==1)
   {
       //cout<<B[n-1-ii]<<endl;
       int kk=m-B[n-ii];
       //cout<<kk<<" ii= "<<ii<<endl;
       if(kk%ii==0)
        ans=ans-(kk/ii);
       else
        ans=ans-(kk/ii)-1;
   }
   if(ans==0)
   {
       ans=A[0];
       int kk=m-B[0];
       if(kk%n==0)
        ans=ans-(kk/n);
       else
        ans=ans-(kk/n)-1;
   }
    cout<<ans<<endl;

    return 0;
}
