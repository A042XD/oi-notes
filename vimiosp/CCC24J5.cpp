#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N=4e3+5,M=4e3+5;
int n,m,x,y,ans,dx[5]={0,1,0,-1},dy[5]={-1,0,1,0};
char mp[N][N];
bool v[N][N];
void dfs(int y,int x){
  v[y][x]=1;
  if(mp[y][x]=='S')ans+=1;
  else if(mp[y][x]=='M')ans+=5;
  else ans+=10;
  for(int i=0;i<4;i++){
    int nx=x+dx[i],ny=y+dy[i];
    if(nx<1||ny<1||nx>m||ny>n)continue;
    if(mp[ny][nx]=='*'||v[ny][nx])continue;
    dfs(ny,nx);
  }
}
int read(){ // Fast
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)
    scanf("%s",mp[i]+1);
  y=read(),x=read();
  dfs(y+1,x+1);
  printf("%d",ans);
  return 0;
}