#include<iostream>
#include<algorithm>
#include<string>
#define int long long

using namespace std;
const int N=6e6+5,mod=(1ll<<32);
int n,m,ans,p[N],pi[N],t[N];
string a,b,c;

signed main(){
  scanf("%lld%lld",&n,&m);
  cin>>a>>b;c=b+'#'+a;
  for(int i=1,j=0;c[i];i++){
    while(j&&c[i]!=c[j])j=pi[j-1];
    j+=(c[i]==c[j]),pi[i]=j;
    if(pi[i]==m)t[i-2*m]=1;
  }
  for(int i=1;a[i];i++)t[i]+=t[i-1];
  for(int i=1;a[i];i++)t[i]+=t[i-1];
  for(int i=0,r=0,d=0;a[i];i++){
    if(i>r)p[i]=1;
    else p[i]=min(p[2*d-i],r-i+1);
    while(a[i+p[i]]==a[i-p[i]])p[i]++;
    if(i+p[i]-1>r)r=i+p[i-1],d=i;
  }
  for(int i=0;a[i];i++)
    if(p[i]*2-1>=m){
      int l=i-p[i]+1,r=i+p[i]-m,u1=(l+r+1)/2,u2=(l+r)/2;
      ans=(ans+t[r]-t[u1-1]-(t[u2-1]-t[l-2]))%mod;
    }
  printf("%lld",ans);
  return 0;
}
