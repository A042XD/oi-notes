#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=5e5+5;
int n,m,t[N];
void upd(int x,int v){for(;x<=n;x+=x&-x)t[x]+=v;}
int qry(int x,int c=0){for(;x;x-=x&-x)c+=t[x];return c;}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1,x;i<=n;i++)x=read(),upd(i,x),upd(i+1,-x);
  while(m--){
    int op=read(),x=read(),y,z;
    if(op==1)y=read(),z=read(),upd(x,z),upd(y+1,-z);
    else printf("%d\n",qry(x));
  }
  return 0;
}