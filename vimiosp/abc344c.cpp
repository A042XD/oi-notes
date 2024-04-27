#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>

using namespace std;
const int N=1000005;
int n,m,l,q,a[N],b[N],c[N],d[N];
set<int>s;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  m=read();
  for(int i=1;i<=m;i++)b[i]=read();
  l=read();
  for(int i=1;i<=l;i++)c[i]=read();
  q=read();
  for(int i=1;i<=q;i++)d[i]=read();
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      for(int k=1;k<=l;k++)
        s.insert(a[i]+b[j]+c[k]);
  for(int i=1;i<=q;i++)
    if(s.count(d[i]))puts("Yes");
    else puts("No");
  return 0;
}