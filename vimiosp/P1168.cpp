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
int n;
priority_queue<int>x;
priority_queue<int,vector<int>,greater<int>>y;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1;i<=n;i++){
    x.push(read());
    int k=i/2+1;
    while(x.size()>k)y.push(x.top()),x.pop();
    while(y.size()&&x.top()>y.top()){
      int a=x.top(),b=y.top();
      x.pop(),y.pop();
      x.push(b),y.push(a);
    }
    if(i&1)printf("%d\n",x.top());
  }
  return 0;
}