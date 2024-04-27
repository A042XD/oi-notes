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
void add(vector<int>a,vector<int>b,int k=0){
  if(a.size()<b.size())a.resize(b.size());
  if(b.size()<a.size())b.resize(a.size());
  for(int i=0;i<a.size();i++)
    k+=a[i]+b[i],c.push_back(k%10),k/=10;
  if(k)c.push_back(k);
}

signed main(){
  cin>>s1>>s2;
  for(int i=s1.size()-1;~i;i--)a.push_back(s1[i]-'0');
  for(int i=s2.size()-1;~i;i--)b.push_back(s2[i]-'0');
  add(a,b);
  for(int i=c.size()-1;~i;i--)printf("%d",c[i]);
  return 0;
}