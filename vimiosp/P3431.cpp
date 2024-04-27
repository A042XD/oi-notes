#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<string>
#include<map>
#define pii pair<int,int>

using namespace std;
const int N=1e6+5;
int xx[N],yy[N],n,m,k,t[N],f[N];
struct _a{int x,y,w;}a[N];
void upd(int x,int v){for(;x<=k;x+=x&-x)t[x]=max(t[x],v);}
int qry(int x,int c=0){for(;x;x-=x&-x)c=max(c,t[x]);return c;}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read(),k=read();
  for(int i=1;i<=k;i++)
    a[i].x=xx[i]=read(),a[i].y=yy[i]=read(),a[i].w=read();
  sort(xx+1,xx+k+1),sort(yy+1,yy+k+1);
  n=unique(xx+1,xx+k+1)-xx-1,m=unique(yy+1,yy+k+1)-yy-1;
  for(int i=1;i<=k;i++){
    a[i].x=lower_bound(xx+1,xx+n+1,a[i].x)-xx;
    a[i].y=lower_bound(yy+1,yy+m+1,a[i].y)-yy;
  }
  sort(a+1,a+k+1,[](_a a,_a b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
  });
  int ans=0;
  for(int i=1;i<=k;i++){
    f[i]=qry(a[i].y)+a[i].w;
    upd(a[i].y,f[i]);
  }
  for(int i=1;i<=k;i++)ans=max(ans,f[i]);
  printf("%d",ans);
  return 0;
}