#include <iostream>
#include<math.h>
using namespace std;


int main()
{
while(1)
{
int n;
cin>>n;
if(n==-1)
break;
int A[n],sum=0;
for(int i=0;i<n;i++)
{
cin>>A[i];
sum+=A[i];
}
if(sum%n!=0)
cout<<"-1\n";
else{
sum/=n;
int a=0;
for(int i=0;i<n;i++)
{
if(A[i]>sum)
a+=(A[i]-sum);
}
cout<<a<<endl;

}
}
return 0;
}
