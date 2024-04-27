#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int M=1e3+5;
int n,ans,a[M],c[M*32][2],k[M*32],r[M*32],tot;
void ins(int x,int p=0){
  for(int i=32;~i;i--){
    int t=(x>>i)%2;
    if(!c[p][t])c[p][t]=++tot;
    r[p=c[p][t]]++;
  }
  k[p]=x;
}
void del(int x,int p=0){
  for(int i=32;~i;i--){
    int t=(x>>i)%2;
    if(!c[p][t])return;
    r[p=c[p][t]]--;
  }
}
int qry(int x,int p=0){
  r[0]=0;
  for(int i=32;~i;i--){
    int t=(x>>i)%2;
    if(c[p][!t]&&r[c[p][!t]]>0)p=c[p][!t];
    else p=c[p][t];
  }
  return x^k[p];
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read(),ins(a[i]);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if(i!=j){
        del(a[i]),del(a[j]);
        ans=max(ans,qry(a[i]+a[j]));
        ins(a[i]),ins(a[j]);
      }
  printf("%d",ans);
  return 0;
}