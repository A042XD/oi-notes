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
int n,m,a[N],q[N],h=1,t;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++){
    a[i]=read();
    while(h<=t&&a[q[t]]>a[i])t--;
    while(h<=t&&q[h]<i-m+1)h++;
    q[++t]=i;
    if(i>=m)printf("%d ",a[q[h]]);
  }
  h=1,t=0,puts("");
  for(int i=1;i<=n;i++){
    while(h<=t&&a[q[t]]<a[i])t--;
    while(h<=t&&q[h]<i-m+1)h++;
    q[++t]=i;
    if(i>=m)printf("%d ",a[q[h]]);
  }
  return 0;
}