#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;
const int N=65,M=105,D=7005,p=10007;
int n,m,tot,c[D][26],fl[D],dp[M][D];
bool ed[D];
char s[M];
void ins(char s[],int p=0){
  for(int i=0;s[i];i++){
    int t=s[i]-'A';
    if(!c[p][t])c[p][t]=++tot;
    p=c[p][t];
  }
  ed[p]=1;
}
void fail(){
  queue<int>q;
  for(int i=0;i<26;i++)if(c[0][i])q.push(c[0][i]);
  while(q.size()){
    int u=q.front();q.pop();
    for(int i=0;i<26;i++)
      if(c[u][i]){
        fl[c[u][i]]=c[fl[u]][i],q.push(c[u][i]);
        ed[c[u][i]]|=ed[fl[c[u][i]]];
      }
      else c[u][i]=c[fl[u]][i];
  }
}
int qpow(int a,int k,int p){ // Fast pow
  int r=1;
  while (k){
    if(k&1)r=r*a%p;
    a=a*a%p,k/=2;
  }
  return r;
}
int read(){ // Fast Read
  int x=0,f=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
  return x*f;
}

signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)scanf("%s",s+1),ins(s);
  fail();
  dp[0][0]=1;
  for(int i=0;i<m;i++)
    for(int j=0;j<=tot;j++)
      for(int k=0;k<26;k++)
        if(!ed[c[j][k]])
          dp[i+1][c[j][k]]=(dp[i+1][c[j][k]]+dp[i][j])%p;
  int ans=qpow(26,m,p);
  for(int i=0;i<=tot;i++)ans=(ans-dp[m][i]+p)%p;
  cout<<ans;
  return 0;
}