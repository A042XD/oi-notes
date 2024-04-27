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
const int N=65;
int n,a[N];
int qry(int x=0){for(int i=50;~i;i--)x=max(x,x^a[i]);return x;}
bool ins(int x){
  for(int i=50;~i;i--)
    if(!a[i])return a[i]=x,1;
    else x=min(x,x^a[i]);
  for(int i=50;~i;i--)a[i]=min(a[i],a[i]^x);
  return 0;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++)ins(read());
  printf("%lld",qry());
  return 0;
}