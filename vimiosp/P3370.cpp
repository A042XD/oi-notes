#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define ull unsigned long long

using namespace std;
const int N=1e4+5;
int n,b=131,ans;
ull hs[N],p=1e17+7;
char s[N];
ull hx(char s[],ull v=0){
  for(int i=0;s[i];i++)
    v=(v*b+s[i])%p;
  return v;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)scanf("%s",s),hs[i]=hx(s);
  sort(hs+1,hs+n+1);
  for(int i=1;i<=n;i++)ans+=(hs[i]!=hs[i-1]);
  printf("%d",ans);
  return 0;
}