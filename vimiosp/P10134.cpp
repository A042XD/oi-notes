#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e5+5;
int n,m,q,v,f,c[N],p[N],b[N],a[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  int t=read();
  while(t--){
    n=read(),m=read(),q=read(),f=v=0;
    for(int i=1;i<=n;i++)c[i]=read(),a[i]=2147483647;
    while(m--){int x=read(),y=read();a[y]=min(a[y],x);} 
    for(int i=1;i<=n;i++)a[i]=(a[i]==2147483647?0:a[i]);
    int ct=0;
    for(int i=1;i<=n;i++){
      if(a[i]<ct)f=1;
      if(!c[i]&&a[i])c[i]=p[i-1]+1,b[a[i]]=c[i],ct=i;
      else if(!c[i])c[i]=1;
      else if(c[i]&&a[i])b[a[i]]=p[i-1],ct=i;
      p[i]=max(p[i-1],c[i]);
    }
    if(f)puts("-1");
    else {for(int i=1;i<=n;i++)printf("%d ",c[i]);puts("");}

    for(int i=1;i<=n;i++)c[i]=p[i]=b[i]=a[i]=0;
  }
  return 0;
}