#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=5e4+5;
int t,n,k,a[N],ans[N],tp;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    n=read(),k=read();
    for(int i=1;i<=n;i++)a[i]=0;
    for(int i=1;i<=n;i++)a[read()]++;
    for(int i=1;i<=n;i++)read();
    int cnt=0;
    for(int i=1;i<=n;i++){
      if(k*2-cnt<2)break;
      if(a[i]==2)printf("%d %d ",i,i),cnt+=2;
    }
    for(int i=1;i<=n;i++){
      if(k*2-cnt<1)break;
      if(a[i]==1)printf("%d ",i),cnt+=1,ans[++tp]=i;
    }
    puts("");
    cnt=tp;
    //printf("   %d %d\n",cnt,tp);
    while(tp)printf("%d ",ans[tp--]);
    for(int i=1;i<=n;i++){
      if(cnt==k*2)break;
      if(!a[i])printf("%d %d ",i,i),cnt+=2;
    }
    puts("");//puts("");
  }
  return 0;
}