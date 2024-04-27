#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=5e3+5,M=2e5+5;
int n,m,fa[N];
struct _l{int x,y,m;}ln[M];
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
void mrg(int x,int y){if((x=fd(x))!=(y=fd(y)))fa[x]=y;}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();int ans=0,cnt=0;
  for(int i=1;i<=n;i++)fa[i]=i;
  for(int i=1;i<=m;i++)ln[i].x=read(),ln[i].y=read(),ln[i].m=read();
  sort(ln+1,ln+m+1,[](_l a,_l b){return a.m<b.m;});
  for(int i=1;i<=m;i++)
    if(fd(ln[i].x)!=fd(ln[i].y))
      cnt++,ans+=ln[i].m,mrg(ln[i].x,ln[i].y);
  if(cnt!=n-1)puts("orz");
  else printf("%d",ans);
  return 0;
}