#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=3e6+5;
int n,s[N],tp,k[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  vector<int>a(n+10);
  for(int i=1;i<=n;i++){
    a[i]=read();
    while(tp&&a[s[tp]]<a[i])k[s[tp--]]=i;
    s[++tp]=i;
  }
  for(int i=1;i<=n;i++)printf("%d ",k[i]);
  return 0;
}