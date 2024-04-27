#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=1005;
int n,l,r,x,f[N][N],a[N],b[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),l=read(),r=read();
  for(int i=1;i<=n;i++)a[i]=read()+a[i-1];
  for(int i=1;i<=n;i++)b[i]=read()+b[i-1];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      f[i][j]=max(f[i-1][j],f[i][j-1]);
      if(l<=a[j]-a[i-1]&&a[j]-a[i-1]<=r)
        f[i][j]=max(f[i][j],f[i-1][j-1]+b[j]-b[i-1]);
    }  
  printf("%lld",f[n][n]);
  return 0;
}