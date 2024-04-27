#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define int long long // Data type

using namespace std;
const int M=15,N=1e6+5;
int n,m,q,ln[N],e[M][N],pi[2*N];
char t[N],s[N],c[N*2];
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  m=read(),q=read(),scanf("%s",t+1);
  for(int l=1;l<=m;l++){
    scanf("%s",s);
    int k=-1,o=0;
    for(int j=0;s[j];j++,o++)c[++k]=s[j];c[++k]='#';
    for(int j=1;t[j];j++)c[++k]=t[j];
    for(int i=1,j=0;c[i];i++){
      while(j&&c[i]!=c[j])j=pi[j-1];
      j+=(c[i]==c[j]),pi[i]=j;
      if(pi[i]==o)e[l][i-o]=1;
    }
    // for(int i=1;t[i];i++)printf("%d ",e[l][i]);
    // puts("");
    ln[l]=o;
  }
  for(int i=1;i<=m;i++)
    for(int j=1;t[j];j++)
      e[i][j]+=e[i][j-1];
  while(q--){
    int l=read(),r=read(),ans=0;
    for(int i=1;i<=m;i++)
      if(l-2+ln[i]<=r)
        ans+=e[i][r]-e[i][l-2+ln[i]];
    printf("%lld\n",ans);
  }
  return 0;
}