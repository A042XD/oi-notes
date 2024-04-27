#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>

using namespace std;
const int N=5e5+5;
int n,q,a[N],to[N],pr[N],tot;
map<int,int>m;
bool b[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1;i<=n;i++)m[a[i]]=i;tot=n;
  q=read();
  while(q--){
    int op=read(),x=read(),y;
    if(op==1){
      y=read();int k=m[x];b[++tot]=0;
      if(to[k])to[tot]=to[k],pr[to[k]]=tot;
      pr[tot]=k,to[k]=tot;a[tot]=y,m[y]=tot;
    }
    else b[m[x]]=1;
  }
  for(int i=1;i<=n;i++)
    for(int j=i;j;j=to[j])
      if(!b[j])printf("%d ",a[j]);
  return 0;
}