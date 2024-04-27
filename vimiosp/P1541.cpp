#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=350;
int n,m,a[N],b[5],f[45][45][45][45];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1;i<=m;i++)b[read()]++;
  f[0][0][0][0]=a[1];
  for(int x=0;x<=b[1];x++)
    for(int y=0;y<=b[2];y++)
      for(int z=0;z<=b[3];z++)
        for(int w=0;w<=b[4];w++){
          int c=x+y*2+z*3+w*4+1;
          if(x)f[x][y][z][w]=max(f[x][y][z][w],f[x-1][y][z][w]+a[c]);
          if(y)f[x][y][z][w]=max(f[x][y][z][w],f[x][y-1][z][w]+a[c]);
          if(z)f[x][y][z][w]=max(f[x][y][z][w],f[x][y][z-1][w]+a[c]);
          if(w)f[x][y][z][w]=max(f[x][y][z][w],f[x][y][z][w-1]+a[c]);
        }
  printf("%lld",f[b[1]][b[2]][b[3]][b[4]]);
  return 0;
}