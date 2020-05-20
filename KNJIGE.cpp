#include <iostream>
#include<cmath>
using namespace std;

int main() {


	    int n;
	    cin>>n;

        int A[n],k=0;
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
            if(A[i]==n)
                k=i;
        }
        int kk=n-1,s=1;
        for(int i=k;i>=0;i--)
        {
         if(A[i]==kk)
         {
             s++;
             kk--;
         }

        }
        cout<<n-s<<endl;


	return 0;
}
