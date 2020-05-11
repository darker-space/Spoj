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


int main() {

int T;
cin>>T;
while(T--)
{
    int n,k,t,f;
    cin>>n>>k>>t>>f;
    cout<<((((f-n)*k)/(k-1))+n)<<endl;
}
	return 0;
}
