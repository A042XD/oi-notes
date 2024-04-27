#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>
#define int long long // Data type

using namespace std;
const int N=0;
int n,k;
int f(int n){
  if(n>k&&(n-k)%2==0&&(n+k)%2==0)return f((n-k)/2)+f((n+k)/2);
  return 1;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),k=read();
  printf("%d",f(n));
  return 0;
}