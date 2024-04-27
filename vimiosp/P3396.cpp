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
const int N=1.5e5+5,B=405;
int n,m,fn[B][B],a[N];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();int b=sqrt(n);
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1;i<=n;i++)
    for(int j=1;j<=b;j++)fn[j][i%j]+=a[i];
  while(m--){
    char op;
    cin>>op;int x=read(),y=read();
    if(op=='A'){
      if(x<b)printf("%lld\n",fn[x][y]);
      else{
        int ans=0;
        for(int i=y;i<=n;i+=x)ans+=a[i];
        printf("%lld\n",ans);
      }
    }
    else{
      for(int i=1;i<=b;i++)fn[i][x%i]+=y-a[x];
      a[x]=y;
    }
  }
  return 0;
}