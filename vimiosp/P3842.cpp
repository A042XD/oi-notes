#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=2e4+5;
int n,l[N],r[N],k[N],f[N][2];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)l[i]=read(),r[i]=read();
  f[1][0]=r[1]-1+r[1]-l[1],f[1][1]=r[1]-1;
  for(int i=2;i<=n;i++){
    f[i][0]=min(f[i-1][0]+abs(r[i]-l[i-1])+r[i]-l[i],f[i-1][1]+abs(r[i]-r[i-1])+r[i]-l[i])+1;
    f[i][1]=min(f[i-1][0]+abs(l[i]-l[i-1])+r[i]-l[i],f[i-1][1]+abs(l[i]-r[i-1])+r[i]-l[i])+1;
  }
  printf("%d\n",min(f[n][0]+n-l[n],f[n][1]+n-r[n]));
  return 0;
}