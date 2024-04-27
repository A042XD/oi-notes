#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<string>

using namespace std;
const int N=2e4+5;
int n,ans;
string s[N];
map<string,int>m1;
map<string,bool>m2;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++){
    cin>>s[i];
    m2.clear();
    int ln=s[i].size();
    for(int j=0;s[i][j];j++)
      for(int k=j;s[i][k];k++){
        string tmp=s[i].substr(j,k-j+1);
        if(!m2[tmp])m2[tmp]=1,m1[tmp]++;
      }
  }
  for(int i=1;i<=n;i++)ans+=m1[s[i]]-1;
  printf("%d",ans);
  return 0;
}