#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e5+5;
int n,q,st[N][20];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}
int qry(int x,int y){
  if(x==y)return st[x][0];
  int d=__lg(y-x+1);
  return max(st[x][d],st[y-(1<<d)+1][d]);
}

signed main(){
  n=read(),q=read();
  for(int i=1;i<=n;i++)st[i][0]=read();
  for(int p=1;p<=__lg(n);p++)
    for(int i=1;i<=n-(1<<p)+1;i++)
      st[i][p]=max(st[i][p-1],st[i+(1<<(p-1))][p-1]);
  while(q--){
    int l=read(),r=read();
    printf("%d\n",qry(l,r));
  }
  return 0;
}