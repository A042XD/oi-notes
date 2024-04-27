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
const int N=3005;
int t,n,k,p,ans,ct[N][N],f[N][N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read(),k=read(),p=read();
    for(int i=0;i<=n;i++)f[i][0]=1;
    for(int i=0;i<=k;i++)f[0][i]=1;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=k;j++)
        f[i][j]=(f[i][j-1]+f[i-1][j])%p;
    for(int i=0;i<=n;i++)ct[i][0]=f[i][0];
    for(int i=0;i<=k;i++)ct[0][i]=1;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=k;j++)
        ct[i][j]=(f[i][j]+ct[i][j-1])%p;
    
    for(int i=0;i<=n;i++,puts(""))
      for(int j=0;j<=k;j++)
        printf("%4lld ",f[i][j]);
    puts("");
    for(int i=0;i<=n;i++,puts(""))
      for(int j=0;j<=k;j++)
        printf("%4lld ",ct[i][j]);
    puts("");
    
    for(int i=1;i<=n;i++)
      for(int j=2;j<=n-i+1;j++)
        ans=(ans+ct[i-1][k-1]*ct[n-j-i+1][k-1])%p,printf("   %lld %lld\n",ct[i-1][k-1],ct[n-j-i+1][k-1]);
    printf("%lld\n",ans+k);
    for(int i=0;i<=n;i++)
      for(int j=0;j<=k;j++)f[i][j]=ct[i][j]=0;
    ans=0;
  }
  return 0;
}