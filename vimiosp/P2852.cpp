#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=3e4+5,M=1e6+5;
int n,m,k,x[M],y[M],c[M],sa[N],rk[N],ht[N],ans,s[N],q[N],h=1,t=0;
void gtsa(){
  for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
  for(int i=2;i<=m;i++)c[i]+=c[i-1];
  for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
  for(int k=1;k<=n;k*=2){
    int num=0;
    for(int i=n-k+1;i<=n;i++)y[++num]=i;
    for(int i=1;i<=n;i++)if(sa[i]>k)y[++num]=sa[i]-k;
    for(int i=1;i<=m;i++)c[i]=0;
    for(int i=1;i<=n;i++)c[x[i]]++;
    for(int i=2;i<=m;i++)c[i]+=c[i-1];
    for(int i=n;i>=1;i--)sa[c[x[y[i]]]--]=y[i],y[i]=0;
    swap(x,y),x[sa[1]]=num=1;
    for(int i=2;i<=n;i++)
      x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?num:++num);
    if(num==n)break;m=num;
  }
}
void gtht(){
  for(int i=1;i<=n;i++)rk[sa[i]]=i;
  for(int k=0,i=1;i<=n;i++){
    if(k)k--;
    while(s[i+k]==s[sa[rk[i]-1]+k])k++;
    ht[rk[i]]=k;
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),k=read(),m=1e6;
  for(int i=1;i<=n;i++)s[i]=read();
  gtsa(),gtht();
  for(int i=2;i<=n;i++){
    while(h<=t&&ht[q[t]]>ht[i])t--;
    while(h<=t&&q[h]<i-k+2)h++;
    q[++t]=i;
    ans=max(ans,ht[q[h]]);
  }
  printf("%d",ans);
  return 0;
}