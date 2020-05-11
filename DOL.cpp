#include <iostream>
#include<string>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
#include<typeinfo>
#include <stdlib.h>

typedef long long ll;

using namespace std;


int main() {

  int T;
  cin>>T;
  int N=T;
  while(T--)
  {

    ll n;
    cin>>n;
    while(n%2==0)
        n>>=1;
    cout<<"Case "<<N-T<<": "<<n<<endl;

  }
	return 0;
}
