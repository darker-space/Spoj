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

ll m =1000000007;


ll gcd(ll a,ll b)
{

    if(b==0)
        return a;
    else return gcd(b,a%b);
}

int main() {

   int T;
   cin>>T;
   int kk=T;
   while(T--)
   {
       int a,b,c;
       cin>>a>>b>>c;
       int k=gcd(a,b);
       if(c%k==0)
        cout<<"Case "<<kk-T<<": Yes\n";
       else
        cout<<"Case "<<kk-T<<": No\n";

   }
	return 0;
}
