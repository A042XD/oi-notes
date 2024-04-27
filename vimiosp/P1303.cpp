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
string s1,s2;
vector<int>a,b,c;
void mul(vector<int>a,vector<int>b){
  c.resize(a.size()+b.size()+1);
  for(int i=0;i<a.size();i++)
    for(int j=0;j<b.size();j++)
      c[i+j]+=a[i]*b[j],c[i+j+1]+=c[i+j]/10,c[i+j]%=10;
  while(c.size()&&!c.back())c.pop_back();
  if(!c.size())c.push_back(0);
}

signed main(){
  cin>>s1>>s2;
  for(int i=s1.size()-1;~i;i--)a.push_back(s1[i]-'0');
  for(int i=s2.size()-1;~i;i--)b.push_back(s2[i]-'0');
  mul(a,b);
  for(int i=c.size()-1;~i;i--)printf("%d",c[i]);
  return 0;
}