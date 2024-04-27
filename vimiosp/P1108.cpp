#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define pii pair<int,int>

using namespace std;
const int N=5005;
int n,a[N],b[N],f[2][N],g[2][N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=b[i]=read();
  sort(b+1,b+n+1,greater<int>());
  int m=unique(b+1,b+n+1)-b-1;

  int now=1,pre=0;
  g[now][0]=1;
  for(int i=0;i<=m;i++)g[pre][i]=1;
  for(int i=1;i<=n;i++,swap(now,pre))
    for(int j=1;j<=m;j++){
      f[now][j]=max(f[pre][j],f[now][j-1]);
      g[now][j]=0;
      if(a[i]==b[j])f[now][j]=max(f[now][j],f[pre][j-1]+1);
      if(a[i]==b[j]&&f[now][j]==f[pre][j-1]+1)g[now][j]+=g[pre][j-1];
      if(f[now][j]==f[pre][j])g[now][j]+=g[pre][j];
      if(f[now][j]==f[now][j-1])g[now][j]+=g[now][j-1];
      if(f[pre][j-1]==f[now][j])g[now][j]-=g[pre][j-1];
    }
  printf("%lld %lld",f[pre][m],g[pre][m]);
  return 0;
}