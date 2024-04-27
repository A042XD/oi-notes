#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=2e5+5;
int t,n,k,a[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    int ans=0;
    for(int i=30;~i;i--){
      int cnt=0;
      for(int j=1;j<=n;j++)
        cnt+=((a[j]>>i)%2==0);
      if(cnt<=k)ans|=(1<<i),k-=cnt;
    }
    printf("%d\n",ans);
  }
  return 0;
}