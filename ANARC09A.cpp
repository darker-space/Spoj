#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>


using namespace std;

int main()
{
int T=0;
 while(1){
T++;
string s;
cin>>s;
if(s[0]=='-')
    break;
stack <char> a;
for(int i=0;i<s.size();i++)
{
    if(s[i]=='}'&&(!a.empty())&&a.top()=='{')
        a.pop();
    else
        a.push(s[i]);

}
int ans=0;
while(!a.empty())
{
  char aa=a.top();
  a.pop();
  if(aa==a.top())
    ans++;
  else
    ans+=2;
  a.pop();
}
cout<<T<<". "<<ans<<endl;



}

    return 0;
}
