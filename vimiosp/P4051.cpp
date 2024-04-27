#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=2e5+5;
int n,p,m,c[N],x[N],y[N],sa[N];
char t[N],s[N];
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
    swap(x,y),x[sa[1]]=1,num=1;
    for(int i=2;i<=n;i++)
      x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
    if(num==n)break;m=num;
  }
}

signed main(){
  scanf("%s",t),p=strlen(t);n=p*2,m=122;
  for(int i=0;t[i];i++)s[i+1]=s[i+p+1]=t[i];
  gtsa();
  for(int i=1;i<=n;i++)if(sa[i]<=p)printf("%c",s[sa[i]+p-1]);
  return 0;
}