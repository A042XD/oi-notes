#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=3e6+5;
int tot,p[N];
bool v[N],c[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  v[1]=1;
  for(int i=2;i<=int(5e4);i++){
    if(!v[i])p[++tot]=i;
    for(int j=1;j<=tot&&i*p[j]<=int(5e4);j++){
      v[i*p[j]]=1;
      if(i==p[j])break;
    }
  }
  
  int t=read();
  while(t--){
    int x=read(),y=read();
    for(int i=1;i<=tot;i++)
      for(int j=x/p[i];j<=y/p[i];j++){
        while(j<=1)j++;
        if(p[i]*j<x||p[i]*j>y)continue;
        c[p[i]*j-x]=1;
      }
    for(int i=x;i<=y;i++)
      if(!c[i-x])printf("%d\n",i);
    for(int i=0;i<=y-x+1;i++)c[i]=0;
  }
  return 0;
}