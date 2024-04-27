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
const int N=2e5+5;
int n,q,a[N],r[N],ans[N],p[N],sz[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),q=read();
  for(int i=1;i<=q;i++){
    a[i]=read();
    if(r[a[i]]){
      ans[a[i]]+=p[i-1]-p[r[a[i]]-1];
      r[a[i]]=0,sz[i]=sz[i-1]-1;
    }
    else{
      r[a[i]]=i,sz[i]=sz[i-1]+1;
    }
    p[i]=p[i-1]+sz[i];
  }
  for(int i=1;i<=n;i++)
    if(r[i]){
      ans[i]+=p[q]-p[r[i]-1];
    }
  for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
  return 0;
}