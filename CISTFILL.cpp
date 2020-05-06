#include <iostream>
#include<stdio.h>
#include<string>
#include<set>
#include<cmath>
#include<algorithm>
#include<vector>
#include<typeinfo>
#include <stdlib.h>
#include<iomanip>
#include<map>
#define N 100000000
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fast         ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long ll;
typedef long double ld;

using namespace std;

class box{
    public:
ld l,b,h,x,v;
//box(ld a,ld bb,ld c,ld d)
//{
//    l=a; b=bb ;h=c; d=x;
//}

ld vol(ld a)
{
    ld k=0;
    return max(k,(min((x+h),a)-x)*b*l);
}
};
ld vv(ld a,ld b,ld c){
return a*b*c;
}

int main()
{
    fast;
    int T;
    cin>>T;
    while(T--)
    {
      int n;
      cin>>n;
      box A[n];
      ld vol1=0,maxh=0,minh=99999999;
      f(i,0,n)
      {
          cin>>A[i].x>>A[i].h>>A[i].b>>A[i].l;
          vol1+=A[i].vol(A[i].x+A[i].h);
          if(maxh<(A[i].h+A[i].x))
          maxh=(A[i].h+A[i].x);
          if(minh>A[i].x)
            minh=A[i].x;
      }
      ld V;
      cin>>V;
      if(V>vol1)
        cout<<"OVERFLOW\n";
      else if(V==vol1)
         cout<<maxh<<endl;

         else{
            ld low=minh,hi=2*maxh,mid=0;

            while(abs((low+(hi-low)/2)-mid)>0.001)
            {
                mid=low+(hi-low)/2;
                //cout<<fixed<<setprecision(5)<<low<<" "<<mid<<" "<<hi<<endl;
                ld vv=0;
                f(i,0,n)
                {
                    vv+=A[i].vol(mid);
                    if(vv>=V)
                        break;
                }
                if(vv>=V)
                    hi=mid;
                else
                    low=mid;
                 //cout<<fixed<<setprecision(5)<<low<<" "<<mid<<" "<<hi<<endl;
            }
         cout<<fixed<<setprecision(2)<<low<<endl;
         }

    }
    return 0;

}
