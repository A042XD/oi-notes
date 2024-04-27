#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#include<map>
#define int long long // Data type
#define pii pair<int,int>

using namespace std;
const int N=0;
int a,b,p;
int qpow(int a,int k,int p){ // Fast pow
  int r=1;
  while (k){
    if(k&1)r=r*a%p;
    a=a*a%p,k/=2;
  }
  return r;
}
int bsgs(int a,int b,int p){
  map<int,int>m;b%=p;int t=ceil(sqrt(p));
  for(int i=1;i<=t;i++)b=b*a%p,m[b]=i;
  a=qpow(a,t,p),b=1;
  for(int i=1;i<=t;i++){
    b=b*a%p;int tmp=m[b];
    if(m[b])return (i*t-tmp+p)%p;
  }
  return -1;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  p=read(),a=read(),b=read();
  int ans=bsgs(a,b,p);
  if(ans==-1)puts("no solution");
  else printf("%lld",ans);
  return 0;
}