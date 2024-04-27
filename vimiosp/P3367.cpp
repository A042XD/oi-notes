#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e6+5;
int n,m,fa[N];
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
  for(int i=1;i<=n;i++)fa[i]=i;
  while(m--){
    int op=read(),x=read(),y=read();
    if(op==1){
      mrg(x,y);
    }
    else{
      puts(fd(x)==fd(y)?"Y":"N");
    }
  }
  return 0;
}