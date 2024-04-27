#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=2e5+5;
int a[N],b[N],n,m,na[N],nb[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();for(int i=1;i<=n;i++)a[i]=read();
  m=read();for(int i=1;i<=m;i++)b[i]=read();
  a[n+1]=1001,b[m+1]=1001;
  for(int i=n;i>=1;i--)
    if(a[i]!=a[i+1])na[i]=i+1;
    else na[i]=na[i+1];
  for(int i=m;i>=1;i--)
    if(b[i]!=b[i+1])nb[i]=i+1;
    else nb[i]=nb[i+1];
  int i=1,j=1;
  while(i<=n&&j<=m){
    if(a[i]!=b[j]){
      if(a[i]<b[j])printf("%d ",a[i++]);
      else printf("%d ",b[j++]);
      continue;
    }
    else{
      if(a[na[i]]<a[i]&&b[nb[j]]<b[j]){
        while(na[i]<=n&&nb[j]<=m&&a[na[i]]==b[nb[j]]&&na[i]-i==nb[j]-j)
          na[i]=na[na[i]],nb[j]=nb[nb[j]];
        if(na[i]-i<nb[j]-j)printf("%d ",a[i++]);
        else if(na[i]-i>nb[j]-j)printf("%d ",b[j++]);
        else{
          if(a[na[i]]<b[nb[j]])printf("%d ",a[i++]);
          else if(a[na[i]]>b[nb[j]])printf("%d ",b[j++]);
          else printf("%d ",b[j++]);
        }
      }
      else{
        if(a[na[i]]<b[nb[j]])printf("%d ",a[i++]);
        else if(a[na[i]]>b[nb[j]])printf("%d ",b[j++]);
        else printf("%d ",b[j++]);
      }
    }
  }
  while(i<=n)printf("%d ",a[i++]);
  while(j<=m)printf("%d ",b[j++]);
  return 0;
}