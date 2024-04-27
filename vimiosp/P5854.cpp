#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<string>
#define int long long // Data type
#define pii pair<int,int>

using namespace std;
const int N=1e7+5;
int ansl,ansr,ls[N],rs[N],w[N],s[N],tp,n;
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read();
  for(int i=1,k=0;i<=n;i++){
    w[i]=read();
    while(k&&w[s[k]]>w[i])k--;
    if(k)rs[s[k]]=i;
    if(k<tp)ls[i]=s[k+1];
    s[tp=++k]=i;
  }
  for(int i=1;i<=n;i++)
    ansl^=i*(ls[i]+1),ansr^=i*(rs[i]+1);
  printf("%lld %lld",ansl,ansr);
  return 0;
}