#include<iostream>

using namespace std;


long long int gcd(long long int a,long long int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
 }



  long long int lcm(long long int a, long long int b)
 {
    return (a*b)/gcd(a, b);
 }

int main()
{

int N;
cin>>N;

while(N--)
{
  long long a,b;
  cin>>a>>b;

  long long c=lcm(a,b);

 cout<<(c/a)<<" "<<(c/b)<<endl;
}

return 0;
}
