#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e3+5;
int t,n;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  while(t--){
    int n=read(),k=read();
    if(k==1){
      for(int i=1;i<=n;i++)printf("%d ",i);
      puts("");
    }
    else if(k==n){
      for(int i=1;i<=n;i++)printf("1 ");
      puts("");
    }
    else puts("-1");
  }
  return 0;
}