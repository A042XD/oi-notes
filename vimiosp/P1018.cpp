#include<iostream>
#define int long long // Data type
using namespace std;
const int N=2e5+5;
int t,n,a[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}


signed main(){
  t=read();
  while(t--){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    int ans=0;
    for(int i=n;i>=2;i--){
      if(a[i]<a[i-1])ans+=a[i-1]-a[i];
    }
    printf("%lld\n",ans);
  }
  return 0;
}