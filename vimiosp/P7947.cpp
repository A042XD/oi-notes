#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=1e4+5;
int n,k,p[N],cnt,tot,r[N];bool v[N];
void euler(int n){
  v[1]=1;
  for(int i=2;i<=n;i++){
    if(!v[i])p[++cnt]=i;
    for(int j=1;j<=cnt&&i*p[j]<=n;j++){
      v[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),k=read();euler(10000);
  for(int i=1;p[i]<=n&&n>1;i++)
    while(n>1&&n%p[i]==0)n/=p[i],r[i]++,tot++;
  int ans=0;
  for(int i=1;i<=10000;i++)if(r[i])ans+=r[i]*p[i];
  if(ans>k)puts("-1"),exit(0);
  printf("%d\n",tot+k-ans);
  for(int i=1;i<=10000;i++)
    for(int j=1;j<=r[i];j++)
      printf("%d ",p[i]);
  for(int i=1;i<=k-ans;i++)
    printf("1 ");
  return 0;
}