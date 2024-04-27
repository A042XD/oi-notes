#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=4e4+5,M=2e5+5;
int n,m,fa[N];
struct r_{
  int a,b,r;
  friend bool operator < (r_ a,r_ b){return a.r>b.r;}
}e[M];
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
void mrg(int x,int y){if((x=fd(x))!=(y=fd(y)))fa[x]=y;}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)fa[i]=i,fa[i+n]=i+n;
  for(int i=1;i<=m;i++)e[i].a=read(),e[i].b=read(),e[i].r=read();
  sort(e+1,e+m+1);
  for(int i=1;i<=m;i++){
    int x=e[i].a,y=e[i].b,w=e[i].r;
    if(fd(x)==fd(y))printf("%d",w),exit(0);
    else mrg(x,y+n),mrg(x+n,y);
  }  
  printf("0");
  return 0;
}