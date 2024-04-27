#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=5e5+5;
int n,m,t[N];
void chg(int x,int v){for(;x<=n;x+=x&-x)t[x]+=v;}
int qry(int x,int c=0){for(;x;x-=x&-x)c+=t[x];return c;}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++){
    int x=read();
    chg(i,x),chg(i+1,-x);
  }
  while(m--){
    int op=read(),x=read(),y,k;
    if(op==1){
      y=read(),k=read();
      chg(x,k),chg(y+1,-k);
    }
    else{
      printf("%d\n",qry(x));
    }
  }
  return 0;
}