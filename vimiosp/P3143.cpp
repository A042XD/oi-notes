#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=50005;
int n,a[N],k,s[N],e[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),k=read();
  for(int i=1;i<=n;i++)a[i]=read();
  sort(a+1,a+n+1);

  int l=1;
  for(int r=1;r<=n;r++){
    while(a[r]-a[l]>k)l++;
    e[r]=r-l+1;
    s[l]=r-l+1;
  }
  while(l<n)l++,s[l]=n-l+1;
  int mx=e[1],ans=0;
  for(int i=2;i<=n;i++){
    mx=max(mx,e[i-1]);
    ans=max(ans,s[i]+mx);
  }
  printf("%d",ans);
  return 0;
}