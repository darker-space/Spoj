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
typedef long long ll;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int T;
   cin>>T;
   vector <int> V;
   map <int,int> frq;
   ll cnt1=0,cnt2=0;
   while(T--)
   {
    string s;
    cin>>s;
    int a;
    cin>>a;
    if(s[0]=='i'){
        V.push_back(a);
        if(frq[a]==0)
            cnt1++;
        else if(frq[a]==1)
            cnt2++;
        frq[a]++;
    }
    else{
            auto itr=find(V.begin(),V.end(),a);
    if(itr!=V.end()){
        V.erase(itr);
        frq[a]--;
        if(frq[a]==0){
            frq.erase(a);
            cnt1--;
        }
        if(frq[a]==1)
            cnt2--;
    }
    }
//    for(auto&x:V)
//        cout<<x<<" ";
//    cout<<endl;

    int key1=cnt2,key2=cnt1-cnt2;
//    for(auto it=frq.begin();it!=frq.end();it++){
//        if(it->second>1)
//            key1++;
//        else if(it->second==1)
//            key2++;
//    }
    //cout<<"key1= "<<key1<<" key2= "<<key2<<endl;
    if(key1==1&&key2==0)
        cout<<"homo\n";
    else if(key1==0&&key2>1)
        cout<<"hetero\n";

    else if((key1==1&&key2>0)||key1>1)
        cout<<"both\n";
    else
        cout<<"neither\n";

   }


    return 0;

}
