#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=3e4+5;
int n,k,a[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  k=read(),n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  sort(a+1,a+n+1);
  int ans=n;
  for(int x=1,y=n;y>=x;y--)
    if(y!=x){
      if(a[y]+a[x]<=k)x++,ans--;
    }
  printf("%d",ans);
  return 0;
}