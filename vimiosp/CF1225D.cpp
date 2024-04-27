#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#define int long long // Data type
#define ull unsigned long long

using namespace std;
const int N=1e6+5,base=131,mod=1e9+7;
int tot,n,k,ans,pr[N],pid[N],a[N];
map<int,int>mp;
bool isp[N];
ull p[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
void sieve(int n){
  isp[1]=1;
  for(int i=2;i<=n;i++){
    if(!isp[i])pr[++tot]=i,pid[i]=tot;
    for(int j=1;j<=tot&&i*pr[j]<=n;j++){
      isp[i*pr[j]]=1;
      if(i%pr[j]==0)break;
    }
  }
}

signed main(){
  n=read(),k=read();sieve(1e5),p[0]=1;
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1;i<=tot;i++)p[i]=p[i-1]*(ull)base;
  for(int j=1;j<=n;j++){
    int x=a[j];ull h1=0,h2=0;
    for(int i=1;i<=tot;i++){
      int cnt=0;
      if(x==1||pr[i]*pr[i]>x)break;
      if(x%pr[i])continue;
      while(x%pr[i]==0)x/=pr[i],cnt++;
      cnt%=k;
      if(cnt)h1+=p[i]*cnt,h2+=p[i]*(k-cnt);
    }
    if(!isp[x])h1+=p[pid[x]],h2+=p[pid[x]]*(k-1);
    ans+=mp[h2];mp[h1]++;
  }
  printf("%lld\n",ans);
  return 0;
}