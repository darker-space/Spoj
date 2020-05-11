#include<iostream>

using namespace std;

long long fun(long long n)
{
  if(n==1)
  return 2;
  else
  return ((n*(3*n)+n)/2)%1000007;
}

int main()
{

int N;
cin>>N;

while(N--)
{
  long long n;
  cin>>n;
  cout<<fun(n)<<endl;
}

return 0;
}
