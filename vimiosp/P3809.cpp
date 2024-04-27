#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e6+5;
int n,x[N],y[N],c[N],sa[N],m;
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
    swap(x,y);x[sa[1]]=num=1;
    for(int i=2;i<=n;i++)
      x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?num:++num);
    if(num==n)break;m=num;
  }
}

signed main(){
  scanf("%s",s+1),m=122,n=strlen(s+1);
  gtsa();
  for(int i=1;s[i];i++)printf("%d ",sa[i]);
  return 0;
}