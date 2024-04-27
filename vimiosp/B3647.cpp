#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=105,M=4505;
int n,m,dis[N][N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  memset(dis,0x3f3f3f3f,sizeof(dis));
  for(int i=1;i<=m;i++){
    int u=read(),v=read(),w=read();
    if(w<dis[u][v])dis[u][v]=dis[v][u]=w;
  }
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        if(i!=j)
          dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
  for(int i=1;i<=n;i++,puts(""))
    for(int j=1;j<=n;j++)
      printf("%d ",dis[i][j]==0x3f3f3f3f?0:dis[i][j]);
  return 0;
}