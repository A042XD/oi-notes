#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data types
#define pii pair<int,int>

using namespace std;
const int N=4e4+5;
int n,p[N],tot,f[N];bool v[N];
void euler(int n){
  p[1]=f[1]=1;
  for(int i=2;i<=n;i++){
    if(!v[i])p[++tot]=i,f[i]=i-1;
    for(int j=1;j<=tot&&i*p[j]<=n;j++){
      v[i*p[j]]=1;
      if(i%p[j]==0){f[i*p[j]]=f[i]*p[j];break;}
      f[i*p[j]]=f[i]*(p[j]-1);
    }
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  if(n==1)puts("0"),exit(0);
  euler(n);
  int ans=0;
  for(int i=0;i<n;i++)ans+=f[i];
  printf("%lld",ans*2+1);
  return 0;
}