#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long // Data type

using namespace std;
const int N=2e5+5;
int t,n,m,a[N];
char s[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read(),m=read();
    int r=1;
    for(int i=1;i<=n;i++){
      a[i]=read();
      if(a[i]%m)r=r*a[i]%m;
    }
    scanf("%s",s);
    int l=1,r=n;
    for(int i=0;s[i];i++){
      printf("%lld ",r);
      if(s[i]=='L'){
        if(a[l]%m)r=r/a[l]%m;
        
      }
    }
  }
  return 0;
}