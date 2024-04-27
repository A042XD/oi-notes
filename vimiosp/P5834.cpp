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
const int N=1e6+5;
int k;
int s[9]={1,14,13,11,8,7,4,2,1};
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  k=read();
  int ans=(k/8+(k%8>0))*15-s[k%8];
  printf("%lld",ans);
  return 0;
}