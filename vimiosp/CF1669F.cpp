#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define pii pair<int,int>

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
    int ans=0,a1=0,a2=0;
    for(int i=1,j=n;i<=n;i++){
      a1+=a[i];
      while(i<j&&a2<a1)a2+=a[j--];
      if(a1==a2)ans=max(ans,n-(j-i));
      if(i==j)break;
    }
    printf("%lld\n",ans);
  }
  return 0;
}