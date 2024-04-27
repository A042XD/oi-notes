#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>

using namespace std;
stack<int>s;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  int x;
  while(x=read())s.push(x);puts("0");
  while(s.size())printf("%d\n",s.top()),s.pop();  
  return 0;
}