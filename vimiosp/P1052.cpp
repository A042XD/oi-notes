#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e6+5,M=105;
int n,m,s,t,a[M],f[N];
bool v[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),s=read(),t=read(),m=read();
  if(s==t){
    int ans=0;
    for(int i=1;i<=m;i++)ans+=(read()%s==0);
    printf("%d",ans),exit(0);
  }
  for(int i=1;i<=m;i++)a[i]=read();
  sort(a+1,a+m+1),a[0]=0;

  int dis=0;
  for(int i=1;i<=m;i++){
    if(a[i]-a[i-1]>71)dis+=71;
    else dis+=a[i]-a[i-1];
    v[dis]=1;
  }
  if(n-a[m]>71)dis+=71;
  else dis+=n-a[m];

  for(int i=1;i<=dis;i++){
    f[i]=2e9;
    for(int j=s;j<=t;j++)
      if(i>=j)f[i]=min(f[i],f[i-j]+v[i]);
  }
  printf("%d",f[dis]);
  return 0;
}