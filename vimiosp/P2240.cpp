#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=105;
int n,t;
struct _n{
  int x,y;
  friend bool operator<(_n a,_n b){
    return a.x*1.0/a.y<b.x*1.0/b.y;
  }
};
priority_queue<_n>q;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),t=read();
  for(int i=1,u,v;i<=n;i++)
    u=read(),v=read(),q.push({v,u});
  double ans=0;
  while(t>0&&q.size()){
    auto u=q.top();q.pop();
    if(u.y>t)ans+=t*(u.x*1.0/u.y),t=0;
    else ans+=u.x,t-=u.y;
  }
  printf("%.2lf",ans);
  return 0;
}