#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long

using namespace std;
const int N=1e6+5;
int n,p[N],t[N],m,sm,k,y=19930726,ans=1;
char s[N];
int read(){
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
int qpow(int x,int k){
  int r=1;
  while(k){
    if(k&1)r=(r*x)%y;
    x=(x*x)%y,k/=2;
  }
  return r;
}

signed main(){
  n=read(),k=read();
  scanf("%s",s);
  for(int i=0,r=0,d=0;s[i];i++){
    if(i>r)p[i]=1;
    else p[i]=min(p[2*d-i],r-i+1);
    while(s[i-p[i]]==s[i+p[i]]&&i+p[i]<n)p[i]++;
    if(i+p[i]-1>r)r=i+p[i]-1,d=i;
    sm+=p[i],m=max(m,p[i]);
  }
  if(sm<k)puts("-1"),exit(0);  
  for(int i=0;s[i];i++)t[1]++,t[1+p[i]]--;
  for(int i=1;i<=m;i++)t[i]+=t[i-1]; 
  for(int i=m;i>=1&&k;i--)
    if(k>=t[i])ans=(ans*qpow(i*2-1,t[i]))%y,k-=t[i];
    else ans=(ans*qpow(i*2-1,k))%y,k=0;
  printf("%lld",ans);
  return 0;
}
