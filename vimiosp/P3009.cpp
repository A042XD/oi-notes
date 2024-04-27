#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>
#define int long long // Data type

using namespace std;
const int N=1e6+5;
int n,a[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();

  int k=a[1],ans=a[1];
  for(int i=2;i<=n;i++){
    if(k<0)k=a[i];
    else k+=a[i];
    ans=max(ans,k);
  }
  printf("%lld",ans);
  return 0;
}