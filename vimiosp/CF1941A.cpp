#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=105;
int t,n,m,k,a[N],b[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=m;i++)b[i]=read();
    int ans=0;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(a[i]+b[j]<=k)ans++;
    printf("%d\n",ans);
  }
  return 0;
}