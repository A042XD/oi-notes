#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e5+5;
int n,m,x[N],y[N],sa[N],ht[N],rk[N],c[N];
char s[N];
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
  for(int i=1,k=0;i<=n;i++){
    if(!rk[i])continue;
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
  m=122;
  scanf("%s",s+1),n=strlen(s+1);
  long long ans=n*1ll*(n+1)/2;
  gtsa(),gtht();
  for(int i=1;i<=n;i++)ans-=ht[i];
  printf("%lld\n",ans);
  return 0;
}