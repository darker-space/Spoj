#include<iostream>
#include<stdlib.h>

using namespace std;


int main()
{

    int n;
   cin>>n;

    while(n--)
    {
       int a,b;
       cin>>a;
       int A[a];
       int i=a;
       while(i--)
       {
          cin>>A[i];
       }
       cin>>b;
       int B[b];
       i=b;
       int k=1000000;
       while(i--)
       {
           cin>>B[i];
           int j;
           for(j=0;j<a;j++)
           {

               if( abs(A[j]-B[i])<k)
                k= abs(A[j]-B[i]);


           }
       }
       cout<<k<<"\n";



    }

    return 0;
}
