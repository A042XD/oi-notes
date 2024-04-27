#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=5e4+5;
int n,m,x[N],y[N],c[N],sa[N],rk[N],ht[N];
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
  int t=read();
  while(t--){
    m=128;
    scanf("%s",s+1);n=strlen(s+1);
    unsigned long long k=0,ans=1ll*n*(n+1)/2;
    gtsa(),gtht();
    for(int i=2;i<=n;i++)ans-=ht[i];
    cout<<ans<<endl;
    for(int i=0;i<=n+2;i++)ht[i]=sa[i]=rk[i]=x[i]=y[i]=c[i]=0;
  }
  return 0;
}