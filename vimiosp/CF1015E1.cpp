#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=105;
int n,m,cnt,d1[N][N],d2[N][N],d3[N][N],d4[N][N],v[N][N];
char p[N][N];
bool r[N][N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)scanf("%s",p[i]+1);
  for(int i=1;i<=n;i++){
    int l=1,r=1;
    while(r<=m){
      while(p[i][r]=='.')r++;l=r;
      while(p[i][r+1]=='*')r++;
      while(l<=r)d1[i][l]=r-l,l++;
      r++;
    }
  }
  for(int i=1;i<=m;i++){
    int l=1,r=1;
    while(r<=n){
      while(p[r][i]=='.')r++;l=r;
      while(p[r+1][i]=='*')r++;
      while(l<=r)d2[l][i]=r-l,l++;
      r++;
    }
  }
  for(int i=1;i<=n;i++){
    int l=m,r=m;
    while(r>=1){
      while(p[i][r]=='.')r--;l=r;
      while(p[i][r-1]=='*')r--;
      while(l>=r)d3[i][l]=l-r,l--;
      r--;
    }
  }
  for(int i=1;i<=m;i++){
    int l=n,r=n;
    while(r>=1){
      while(p[r][i]=='.')r--;l=r;
      while(p[r-1][i]=='*')r--;
      while(l>=r)d4[l][i]=l-r,l--;
      r--;
    }
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(p[i][j]=='*')
        v[i][j]=min(min(d1[i][j],d2[i][j]),min(d3[i][j],d4[i][j]));
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(v[i][j]){
        cnt++;
        r[i][j]=1;
        for(int k=1;k<=v[i][j];k++)r[i+k][j]=r[i-k][j]=r[i][j+k]=r[i][j-k]=1;
      }
  bool f=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(p[i][j]=='*'&&r[i][j]==0)f=1;
  if(f)puts("-1");
  else{
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(v[i][j])printf("%d %d %d\n",i,j,v[i][j]);
  }
  return 0;
}