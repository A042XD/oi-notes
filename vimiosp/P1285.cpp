#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=105;
int n,t[2],ansa,ansb;
bool a[N][N],b[N][N],col[N],v[N],cc[N][2],ct[N][2];
bool dfs(int x,bool c){
  v[x]=1,col[x]=c,t[c]++,cc[x][c]=1;
  for(int i=1;i<=n;i++)
    if(b[x][i]){
      if(v[i]&&col[i]==c)return 1;
      if(!v[i]&&dfs(i,!c))return 1;
    }
  return 0;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1,x;i<=n;i++)
    while(x=read())a[i][x]=1;
  for(int i=1;i<=n;i++)
    for(int j=1;j<i;j++)
      b[i][j]=b[j][i]=!(a[i][j]&&a[j][i]);
  for(int i=1;i<=n;i++)
    if(!v[i]){
      t[0]=t[1]=0;
      int g=0;
      if(dfs(i,0))puts("No Solution"),exit(0);
      if(t[0]<t[1]&&ansa<ansb)g=1;
      if(t[0]>t[1]&&ansa>ansb)g=1;
      ansa+=t[g],ansb+=t[!g];
      for(int j=1;j<=n;j++)ct[j][0]|=cc[j][g],ct[j][1]|=cc[j][!g];
      for(int j=1;j<=n;j++)cc[j][0]=cc[j][1]=0;
    }
  printf("%d ",ansa);
  for(int i=1;i<=n;i++)if(ct[i][0])printf("%d ",i);
  printf("\n%d ",ansb);
  for(int i=1;i<=n;i++)if(ct[i][1])printf("%d ",i);
  return 0;
}