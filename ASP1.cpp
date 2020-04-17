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
  while(T--)
  {
    ll n;
    cin>>n;
    int A[n];
    ll k=1-n,ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        ans+=k*A[i];
        k+=2;
    }

    cout<<ans<<endl;

  }
	return 0;
}
