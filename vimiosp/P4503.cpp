#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ull unsigned long long

using namespace std;
const int b=131,N=3e4+5,L=205,S=64;
const ull p=1e17+7;
int n,q,l;
ull hs1[N][L],hs2[N][L],hs[N],ans;
char s[N][L];
void hx(int x){
  for(int i=1;i<=l;i++)
    hs1[x][i]=(hs1[x][i-1]*131+s[x][i])%p;
  for(int i=l;i>=1;i--)
    hs2[x][i]=(hs2[x][i+1]*137+s[x][i])%p;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),l=read(),q=read();
  for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
  for(int i=1;i<=n;i++)hx(i);
  for(int i=1;i<=l;i++){
    for(int j=1;j<=n;j++)
      hs[j]=(hs1[j][i-1]*179+hs2[j][i+1]*233)%p;
    sort(hs+1,hs+n+1);
    for(int j=1;j<=n;j++){
      int cnt=1;
      while(hs[j]==hs[j+1])j++,cnt++;
      ans+=cnt*(cnt-1)/2;
    }
  }
  cout<<ans;
  return 0;
}