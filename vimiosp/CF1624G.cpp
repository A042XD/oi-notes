#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=2e5+5;
int t,n,m,f[N];bool v[N];
struct{int x,y,w;}l[N];
int fd(int x){return x==f[x]?x:f[x]=fd(f[x]);}
void mrg(int x,int y){if((x=fd(x))!=(y=fd(y)))f[x]=y;}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read(),m=read();int ans=0;
    for(int i=1;i<=m;i++)v[i]=0;
    for(int i=1;i<=m;i++)l[i].x=read(),l[i].y=read(),l[i].w=read();
    for(int k=31;k>=0;k--){
      for(int i=1;i<=n;i++)f[i]=i;
      for(int i=1;i<=m;i++)
        if(!v[i]&&((l[i].w>>k)&1)==0)
          mrg(l[i].x,l[i].y);
      int f=0,r=fd(1);
      for(int i=2;i<=n;i++)if(fd(i)!=r){f=1;break;}
      if(f)ans+=(1ll<<k);
      else{
        for(int i=1;i<=m;i++)if((l[i].w>>k)&1)v[i]=1;
      }
    }
    printf("%lld\n",ans);
  }  
  return 0;
}