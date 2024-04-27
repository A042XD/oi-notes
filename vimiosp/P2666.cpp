#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=10005;
int n,ans;
void dfs(int x,int s){
  if(x>4){
    if(s==n)ans++;
    return;
  }
  if(s>n)return;
  for(int i=0;s+i*i<=n;i++)
    dfs(x+1,s+i*i);
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  dfs(1,0);
  printf("%d",ans);
  return 0;
}