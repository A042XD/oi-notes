#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e4+5;
int t,n,a[5];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  t=read();
  a[4]=10000;
  a[3]=1000;
  a[2]=100;
  a[1]=10;
  a[0]=1;
  while(t--){
    n=read();
    queue<int>q;
    for(int i=4;~i;i--)
      if(n/a[i])
        q.push(n/a[i]*a[i]),n%=a[i];
    printf("%d\n",q.size());
    while(q.size())printf("%d ",q.front()),q.pop();
    puts("");
  }
  return 0;
}