#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e5+5;
int n,a[N],s[N],tp,k[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    while(tp&&a[s[tp]]<a[i])k[s[tp--]]=i;
    s[++tp]=i;
  }
  for(int i=1;i<=n;i++)printf("%d\n",k[i]);
  return 0;
}