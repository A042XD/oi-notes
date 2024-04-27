#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=0;
vector<int>a,b,c;
string s1,s2;
bool f;
void sub(vector<int>a,vector<int>b,int k=0){
  if(a.size()<b.size())a.resize(b.size());
  if(b.size()<a.size())b.resize(a.size());
  for(int i=a.size()-1;~i;i--)
    if(a[i]!=b[i]){
      if(a[i]<b[i])swap(a,b),f=1;
      break;
    }
  for(int i=0;i<a.size();i++)
    {k=a[i]-b[i];if(k<0)k+=10,a[i+1]--;c.push_back(k);}
  while(c.size()&&!c.back())c.pop_back();
  if(!c.size())f=0,c.push_back(0);
}

signed main(){
  cin>>s1>>s2;
  for(int i=s1.size()-1;~i;i--)a.push_back(s1[i]-'0');
  for(int i=s2.size()-1;~i;i--)b.push_back(s2[i]-'0');
  sub(a,b);
  if(f)printf("-");
  for(int i=c.size()-1;~i;i--)printf("%d",c[i]);
  return 0;
}