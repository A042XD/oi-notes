#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define pii pair<int,int>

using namespace std;
const int N=1e8+5;
int n,p[N],tot;bool v[N];
void euler(int n){
  v[1]=1;
  for(int i=2;i<=n;i++){
    if(!v[i])p[++tot]=i;
    for(int j=1;j<=tot&&i*p[j]<=n;j++){
      v[i*p[j]]=1;
      if(i%p[j]==0)break;
    }
  }
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  int q=read();
  euler(n);
  while(q--)printf("%d\n",p[read()]);
  return 0;
}